#!/usr/bin/env python3
# Create a dictionary
student = {
    "name": "Alice",
    "age": 20,
    "grade": "A",
    "courses": ["Math", "Science", "History"]
}

# Access dictionary values
print("Name:", student["name"])
print("Age:", student["age"])
print("Grade:", student["grade"])
print("Courses:", student["courses"])

# Update a value
student["grade"] = "B"
print("Updated Grade:", student["grade"])

# Add a new key-value pair
student["gender"] = "Female"
print("Gender:", student["gender"])

# Check if a key exists
if "age" in student:
    print("Age is present in the dictionary")

# Remove a key-value pair
del student["courses"]
print("After removing 'courses':", student)

# Get all keys and values
keys = student.keys()
values = student.values()
print("Keys:", keys)
print("Values:", values)

# Iterate over key-value pairs
for key, value in student.items():
    print(key + ":", value)
