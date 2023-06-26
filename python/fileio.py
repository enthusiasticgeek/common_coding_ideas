#!/usr/bin/env python3
# Writing to a file
try:
    with open("data.txt", "w") as file:
        file.write("Hello, File!\n")
        file.write("This is a line of text.\n")
except IOError:
    print("An error occurred while writing to the file.")

# Appending to a file
try:
    with open("data.txt", "a") as file:
        file.write("This line will be appended.\n")
except IOError:
    print("An error occurred while appending to the file.")

# Reading from a file
try:
    with open("data.txt", "r") as file:
        contents = file.read()
        print(contents)
except FileNotFoundError:
    print("File does not exist.")
except IOError:
    print("An error occurred while reading the file.")
