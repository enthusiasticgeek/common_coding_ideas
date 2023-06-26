#!/usr/bin/env python3
# Print function
name = "Alice"
age = 25

print("My name is", name, "and I am", age, "years old.")

# Unicode
message = "こんにちは"
print(message)

# Division operator
result = 7 / 3
print(result)

# Yield from statement
def numbers():
    yield from range(1, 4)
    yield from range(4, 7)

for num in numbers():
    print(num)

# Annotations
def greet(name: str) -> str:
    return "Hello, " + name

result = greet("Alice")
print(result)

# Extended iterable unpacking
numbers = [1, 2, 3, 4, 5]
first, *middle, last = numbers
print(first)
print(middle)
print(last)

# Asynchronous programming
import asyncio

async def hello():
    await asyncio.sleep(1)
    print("Hello, World!")

asyncio.run(hello())

# Type hints
def add(a: int, b: int) -> int:
    return a + b

result = add(3, 4)
print(result)

# Data classes
from dataclasses import dataclass

@dataclass
class Person:
    name: str
    age: int

person = Person("Alice", 25)
print(person)

# F-strings
name = "Alice"
age = 25

message = f"My name is {name} and I am {age} years old."
print(message)
