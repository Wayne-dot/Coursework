import json
import os

def delete_code_between_comments(notebook_path):
    # Load the notebook
    with open(notebook_path, 'r') as f:
        notebook = json.load(f)
    
    for cell in notebook['cells']:
        if cell['cell_type'] == 'code':
            source = cell['source']
            new_source = []
            in_code_block = False
            
            for line in source:
                if '# YOUR CODE STARTS HERE' in line:
                    in_code_block = True
                    new_source.append(line)  # Keep the comment
                elif '# YOUR CODE ENDS HERE' in line:
                    in_code_block = False
                    new_source.append(line)  # Keep the comment
                elif not in_code_block:
                    new_source.append(line)

            cell['source'] = new_source

    # Save the modified notebook
    with open(notebook_path, 'w') as f:
        json.dump(notebook, f, indent=2)

current_directory = os.path.dirname(__file__)
notebook_path = os.path.join(current_directory, 'new', 'new1.ipynb')
delete_code_between_comments(notebook_path)