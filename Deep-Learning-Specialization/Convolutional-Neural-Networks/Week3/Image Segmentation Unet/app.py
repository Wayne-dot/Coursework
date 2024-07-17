
from flask import Flask, render_template, request, Response
import tensorflow as tf
import os
import io
from matplotlib.backends.backend_agg import FigureCanvasAgg as FigureCanvas
import matplotlib.pyplot as plt

app = Flask(__name__)

path = ''
image_path = os.path.join(path, './userdata/')
model_path = './results'
unet = tf.keras.models.load_model(model_path)

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


if __name__ == '__main__':
    app.run(debug=True)
