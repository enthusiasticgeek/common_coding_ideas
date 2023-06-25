#!/usr/bin/env python3
# Metaprogramming in Python
def make_pretty(func):
    def inner():
        print("I'm making it pretty!")
        func()
    return inner

@make_pretty
def ordinary_function():
    print("I'm an ordinary function.")

ordinary_function()
