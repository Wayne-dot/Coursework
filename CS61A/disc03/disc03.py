

def multiply(m, n):
    """Takes two positive integers and returns their product using recursion.
    >>> multiply(5, 3)
    15
    """
    "*** YOUR CODE HERE ***"
    if n == 1:
        return m
    return m + multiply(m, n-1)      #if mutiply(m-1, n), need to be return n + mutiply(m-1, n) 


# print(multiply(3, 9))

def swipe(n):
    """Print the digits of n, one per line, first backward then forward.
    >>> swipe(2837)
    7
    3
    8
    2
    8
    3
    7
    """
    if n < 10:
        print(n)
    else:
        "*** YOUR CODE HERE ***"
        a = n % 10
        print(a)
        swipe(n // 10)
        print(a)

def skip_factorial(n):
    """Return the product of positive integers n * (n - 2) * (n - 4) * ...
    >>> skip_factorial(5) # 5 * 3 * 1
    15
    >>> skip_factorial(8) # 8 * 6 * 4 * 2
    384
    """
    if n == 2:
        return n
    else:
        return n * skip_factorial(n - 2)

# print(skip_factorial(8))
# print(skip_factorial(2))



def hailstone(n):
    """Print out the hailstone sequence starting at n,
    and return the number of elements in the sequence.
    >>> a = hailstone(10)
    10
    5
    16
    8
    4
    2
    1
    >>> a
    7
    >>> b = hailstone(1)
    1
    >>> b
    1
    """
    print(n)
    if n % 2 == 0:
        return even(n)
    else:
        return odd(n)

# recursive case
def even(n):
    return 1 + hailstone(n // 2)

# base case
def odd(n):
    "*** YOUR CODE HERE ***"
    if n == 1:
        return n
    else:
        return 1 + hailstone(3*n + 1)

# a = hailstone(10)
# print(a)






def count_stair_ways(n):
    """Returns the number of ways to climb up a flight of
    n stairs, moving either one step or two steps at a time.
    >>> count_stair_ways(1)
    1
    >>> count_stair_ways(2)
    2
    >>> count_stair_ways(4)
    5
    """
    "*** YOUR CODE HERE ***"
    if n == 1 or n == 2:
        return n
    else:
        return count_stair_ways(n-1) + count_stair_ways(n-2)



def sevens(n, k):
    """Return the (clockwise) position of who says n among k players.

    >>> sevens(2, 5)
    2
    >>> sevens(6, 5)
    1
    >>> sevens(7, 5)
    2
    >>> sevens(8, 5)
    1
    >>> sevens(9, 5)
    5
    >>> sevens(18, 5)
    2
    """
    def f(i, who, direction):
        if i == n:
            return who
        "*** YOUR CODE HERE ***"
        
    return f(1, 1, 1)

def has_seven(n):
    if n == 0:
        return False
    elif n % 10 == 7:
        return True
    else:
        return has_seven(n // 10)