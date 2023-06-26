# Create an initial list
my_list = [1, 2, 3, 4, 5]

# Append an item to the list
my_list.append(6)
print("Appended item:", my_list)

# Remove an item from the list
my_list.remove(3)
print("Removed item:", my_list)

# Insert an item at a specific index
my_list.insert(2, 7)
print("Inserted item:", my_list)

# Get the index of an item in the list
index = my_list.index(4)
print("Index of item 4:", index)

# Count the occurrences of an item in the list
count = my_list.count(2)
print("Count of item 2:", count)

# Sort the list in ascending order
my_list.sort()
print("Sorted list (ascending):", my_list)

# Reverse the list
my_list.reverse()
print("Reversed list:", my_list)

# Copy the list
copy_list = my_list.copy()
print("Copied list:", copy_list)

# Clear all items from the list
my_list.clear()
print("Cleared list:", my_list)
