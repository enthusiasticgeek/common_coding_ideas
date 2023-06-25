#!/usr/bin/env python3
# Duck typing and dynamic dispatch in Python
class Duck:
    def quack(self):
        print("Quack!")

class Person:
    def quack(self):
        print("I'm quacking like a duck!")

def make_quack(obj):
    obj.quack()

duck = Duck()
person = Person()

make_quack(duck)
make_quack(person)
