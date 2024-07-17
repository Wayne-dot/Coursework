import tensorflow as tf
import numpy as np


from flask import Flask, render_template, request, Response
import tensorflow as tf
import os
import io
from matplotlib.backends.backend_agg import FigureCanvasAgg as FigureCanvas
import matplotlib.pyplot as plt

from tensorflow.keras.layers import Input
from tensorflow.keras.layers import Conv2D
from tensorflow.keras.layers import MaxPooling2D
from tensorflow.keras.layers import Dropout 
from tensorflow.keras.layers import Conv2DTranspose
from tensorflow.keras.layers import concatenate

from test_utils import summary, comparator
import os
import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)
import matplotlib.pyplot as plt

path = ''
image_path = os.path.join(path, './data/CameraRGB/')
mask_path = os.path.join(path, './data/CameraMask/')
image_list_orig = os.listdir(image_path)
image_list = [image_path+i for i in image_list_orig]
mask_list = [mask_path+i for i in image_list_orig]
image_list_ds = tf.data.Dataset.list_files(image_list, shuffle=False)
mask_list_ds = tf.data.Dataset.list_files(mask_list, shuffle=False)

for path in zip(image_list_ds.take(3), mask_list_ds.take(3)):
    print(path)

image_filenames = tf.constant(image_list)
masks_filenames = tf.constant(mask_list)

dataset = tf.data.Dataset.from_tensor_slices((image_filenames, masks_filenames))

for image, mask in dataset.take(1):
    print(image)
    print(mask)

def process_path(image_path, mask_path):
    img = tf.io.read_file(image_path)
    img = tf.image.decode_png(img, channels=3)
    img = tf.image.convert_image_dtype(img, tf.float32)

    mask = tf.io.read_file(mask_path)
    mask = tf.image.decode_png(mask, channels=3)
    mask = tf.math.reduce_max(mask, axis=-1, keepdims=True)
    return img, mask

def preprocess(image, mask):
    input_image = tf.image.resize(image, (96, 128), method='nearest')
    input_mask = tf.image.resize(mask, (96, 128), method='nearest')

    return input_image, input_mask

image_ds = dataset.map(process_path)
processed_image_ds = image_ds.map(preprocess)

def conv_block(inputs=None, n_filters=32, dropout_prob=0, max_pooling=True):
    
    conv = Conv2D((n_filters),
                  3,  
                  activation="relu",
                  padding="same",
                  kernel_initializer='he_normal')(inputs)

    conv = Conv2D(n_filters, 
                  3,  
                  activation="relu",
                  padding="same",
                  kernel_initializer="he_normal")(conv)

   
    if dropout_prob > 0:
        conv = Dropout(dropout_prob)(conv)
    
    if max_pooling:
        next_layer = MaxPooling2D((2,2))(conv)
    
    else:
        next_layer = conv
        
    skip_connection = conv
    
    return next_layer, skip_connection

def upsampling_block(expansive_input, contractive_input, n_filters=32):
   
    up = Conv2DTranspose(
                 n_filters,    
                 (3,3),   
                 strides=(2,2),
                 padding="same")(expansive_input)
    
    merge = concatenate([up, contractive_input], axis=3)
    conv = Conv2D(n_filters,   
                 (3,3),   
                 activation="relu",
                 padding="same",
                 kernel_initializer='he_normal')(merge)
    conv = Conv2D(n_filters, 
                 (3,3),  
                 activation="relu",
                 padding="same",
                 kernel_initializer="he_normal")(conv)
    
    return conv

def unet_model(input_size=(96, 128, 3), n_filters=32, n_classes=23):
  
    inputs = Input(input_size)
    cblock1 = conv_block(inputs, n_filters)

    cblock2 = conv_block(cblock1[0], 2*n_filters)
    cblock3 = conv_block(cblock2[0], 4*n_filters)
    cblock4 = conv_block(cblock3[0], 8*n_filters, dropout_prob=0.3)
    cblock5 = conv_block(cblock4[0], 16*n_filters, dropout_prob=0.3, max_pooling=None) 
    
    ublock6 = upsampling_block(cblock5[0], cblock4[1], n_filters*8)

    ublock7 = upsampling_block(ublock6, cblock3[1],  n_filters*4)
    ublock8 = upsampling_block(ublock7, cblock2[1],  n_filters*2)
    ublock9 = upsampling_block(ublock8, cblock1[1],  n_filters)

    conv9 = Conv2D(n_filters,
                 3,
                 activation='relu',
                 padding='same',
                 kernel_initializer='he_normal')(ublock9)
    
    conv10 = Conv2D(n_classes, 1, padding="same")(conv9)
  
    model = tf.keras.Model(inputs=inputs, outputs=conv10)

    return model

img_height = 96
img_width = 128
num_channels = 3

unet = unet_model((img_height, img_width, num_channels))

unet.summary()

unet.compile(optimizer='adam',
              loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
              metrics=['accuracy'])

def display(display_list):
    plt.figure(figsize=(15, 15))

    title = ['Input Image', 'True Mask', 'Predicted Mask']

    for i in range(len(display_list)):
        plt.subplot(1, len(display_list), i+1)
        plt.title(title[i])
        plt.imshow(tf.keras.preprocessing.image.array_to_img(display_list[i]))
        plt.axis('off')
    plt.show()

EPOCHS = 40
VAL_SUBSPLITS = 5
BUFFER_SIZE = 500
BATCH_SIZE = 32
train_dataset = processed_image_ds.cache().shuffle(BUFFER_SIZE).batch(BATCH_SIZE)
print(processed_image_ds.element_spec)
model_history = unet.fit(train_dataset, epochs=EPOCHS)

def create_mask(pred_mask):
    pred_mask = tf.argmax(pred_mask, axis=-1)
    pred_mask = pred_mask[..., tf.newaxis]
    return pred_mask[0]

def show_predictions(dataset=None, num=1):
    if dataset:
        for image, mask in dataset.take(num):
            pred_mask = unet.predict(image)
            display([image[0], mask[0], create_mask(pred_mask)])
    else:
        print("error")

show_predictions(train_dataset, 6)

from tensorflow import keras
save_path = './results'
unet.save(save_path)


app = Flask(__name__)

path = ''
image_path = os.path.join(path, './userdata/')
model_path = './results'
# unet = tf.keras.models.load_model(model_path)

def process_path(image_path):
    img = tf.io.read_file(image_path)
    img = tf.image.decode_png(img, channels=3)
    img = tf.image.convert_image_dtype(img, tf.float32)
    return img

def preprocess(image):
    input_image = tf.image.resize(image, (96, 128), method='nearest')
    return input_image

def create_mask(pred_mask):
    pred_mask = tf.argmax(pred_mask, axis=-1)
    pred_mask = pred_mask[..., tf.newaxis]
    return pred_mask[0]

def show_predictions(file_content):
    img = process_image_from_bytes(file_content)
    img = preprocess(img)
    pred_mask = unet.predict(tf.expand_dims(img, 0))
    return img.numpy(), create_mask(pred_mask).numpy()


def process_image_from_bytes(file_content):
    img = tf.image.decode_png(file_content.getvalue(), channels=3)
    img = tf.image.convert_image_dtype(img, tf.float32)
    return img

import matplotlib.pyplot as plt
import tensorflow as tf

def save_images(display_list, file_paths):
    # Make sure the length of display_list matches the length of file_paths
    assert len(display_list) == len(file_paths), "Length mismatch between display_list and file_paths"

    for i in range(len(display_list)):
        plt.imsave(file_paths[i], tf.keras.preprocessing.image.array_to_img(display_list[i]))


@app.route('/')
def index():
    return render_template('index.html')

@app.route('/', methods=['POST'])
def upload_file():
    if 'file' not in request.files:
        return render_template('index.html', error='No file part')

    file = request.files['file']
    if file.filename == '':
        return render_template('index.html', error='No selected file')

    img, pred_mask = show_predictions(file)
    save_images([pred_mask], ["./static/pred_mask.png"])

    return render_template('index.html', predicted=True)

