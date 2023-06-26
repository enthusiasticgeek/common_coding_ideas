
#In this example, the fibonacci_generator function is defined as a generator using the yield keyword.
#It maintains the state of the sequence and yields the next Fibonacci number in each iteration. 
#When next(fib_gen) is called, it resumes execution from the last yield statement, calculates the next Fibonacci number,
#and then pauses until the next iteration.

def fibonacci_generator():
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a + b

fib_gen = fibonacci_generator()
for i in range(10):
    print(next(fib_gen))

#In this example, the fibonacci_sequence function takes an integer n
#as a parameter and returns a list containing the first n Fibonacci numbers. 
#It calculates the entire sequence at once and stores it in the sequence list. 
#Finally, it returns the complete sequence as the result.

def fibonacci_sequence(n):
    sequence = []
    a, b = 0, 1
    for _ in range(n):
        sequence.append(a)
        a, b = b, a + b
    return sequence

fib_seq = fibonacci_sequence(10)
print(fib_seq)

#In summary, yield is used to create generator functions 
#that can be iterated over, producing one value at a time 
#and maintaining their internal state. On the other hand, 
#return is used to exit a function and return a value as the final result,
#terminating the function's execution.
