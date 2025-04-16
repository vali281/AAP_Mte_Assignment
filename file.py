import os

# Loop through numbers 11 to 50
for i in range(11, 51):
    folder_name = f"ques{i}"
    os.makedirs(folder_name, exist_ok=True)  # Create folder if it doesn't exist

    # Create intro.txt inside the folder
    file_path = os.path.join(folder_name, "intro.txt")
    with open(file_path, "w") as f:
        f.write("")  # You can add default text here if needed

print("Folders created from ques11 to ques50 with intro.txt inside each.")
