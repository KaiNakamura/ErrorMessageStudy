import os
from pygments import highlight
from pygments.lexers import CLexer
from pygments.formatters import ImageFormatter


def generate_screenshots(root_dir, images_dir):
    if not os.path.exists(images_dir):
        os.makedirs(images_dir)

    for folder_name in os.listdir(root_dir):
        folder_path = os.path.join(root_dir, folder_name)
        if os.path.isdir(folder_path) and folder_name.startswith(
            "exercise"
        ):  # Check if it's a directory starting with "exercise"
            # Create corresponding folder in images directory
            exercise_images_dir = os.path.join(images_dir, folder_name)
            if not os.path.exists(exercise_images_dir):
                os.makedirs(exercise_images_dir)

            # Find the .c file in the exercise folder
            for file_name in os.listdir(folder_path):
                file_path = os.path.join(folder_path, file_name)

                if file_name.endswith(".c"):
                    with open(file_path, "r") as file:
                        code = file.read()

                    # Generate the image file path
                    image_name = f"{os.path.splitext(file_name)[0]}.png"
                    image_path = os.path.join(exercise_images_dir, image_name)

                    # Generate the syntax-highlighted image
                    formatter = ImageFormatter(
                        line_numbers=True,
                        style="xcode",
                    )
                    with open(image_path, "wb") as image_file:
                        image_file.write(highlight(code, CLexer(), formatter))

                elif file_name == "error.txt":
                    with open(file_path, "r") as file:
                        error_message = file.read()

                    # Generate the image file path
                    image_name = "error.png"
                    image_path = os.path.join(exercise_images_dir, image_name)

                    # Generate the syntax-highlighted image
                    formatter = ImageFormatter(
                        line_numbers=False,
                        style="bw",
                    )
                    with open(image_path, "wb") as image_file:
                        image_file.write(highlight(error_message, CLexer(), formatter))


if __name__ == "__main__":
    root_directory = "."  # Root directory containing exercise folders
    images_directory = "images"  # Directory to store generated images
    generate_screenshots(root_directory, images_directory)
