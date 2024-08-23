import time
from numpy import average


def fib(n):
    if n < len(fibs):
        return fibs[n]
    fibs.append(fibs[n - 1] + fibs[n - 2])
    return fibs[n]


def fib_timeboxed():
    start_time = time.time()
    n = 0
    fib_sequence = []

    while True:
        elapsed_time = time.time() - start_time
        if elapsed_time >= 0.1:
            break
        fib_sequence.append(fib(n))
        n += 1

    return n


if __name__ == "__main__":
    fib_reached = []
    for _ in range(10):
        fibs = [1, 1]
        fib_reached.append(fib_timeboxed())

    print("Fibonacci sequence calculated 10 times for 0.1s each. " +
          "Highest ns reached:")
    for _ in fib_reached:
        print(_)
    print(f"Mean highest n reached: {average(fib_reached):.0f}")
