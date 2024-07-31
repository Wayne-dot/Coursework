import math

# Fibonacci Sequence
def Fibonaci(n):
    pred, curr = 0, 1
    k = 1
    while k < n:
        pred, curr= curr, pred+curr
        k += 1
    return curr

def square_area(r):
    assert r > 0, 'A length must be positive'
    return math.pi * r * r

def make_adder(n):
    def adder(k):
        return k + n
    return adder

# print(Fibonaci(10))
# print(square_area(3))

# add_three = make_adder(3)
# add_four = make_adder(4)
# print(add_three(3))
# print(add_four(5))

print(make_adder(1)(2))
# first read make_adder(1) and return func make_adder(n) and 1
# then it read the parameter 2, which run the adder function, and return 1 + 2


# Lamdba function
square = lambda x : x * x
print(square(3))