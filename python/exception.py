#!/usr/bin/env python3
def divide_numbers(a, b):
    try:
        result = a / b
        print("Result:", result)
    except ZeroDivisionError:
        print("Error: Division by zero!")
    except TypeError:
        print("Error: Invalid operand type!")
    except Exception as e:
        print("An unexpected error occurred:", str(e))

# Example calls to the function
divide_numbers(10, 2)    # Valid division
divide_numbers(10, 0)    # Division by zero
divide_numbers(10, "2")  # Invalid operand type
divide_numbers(10)       # Missing second operand
