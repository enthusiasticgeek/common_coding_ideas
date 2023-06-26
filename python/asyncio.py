#!/usr/bin/env python3
import asyncio


async def greet(name):
    #hello prints immediately but goodbye prints after asyncio
    print(f"Hello, {name}!")
    await asyncio.sleep(1)  # Simulate asynchronous I/O
    print(f"Goodbye, {name}!")


async def main():
    await asyncio.gather(
        greet("Alice"),
        greet("Bob"),
        greet("Charlie")
    )


asyncio.run(main())
