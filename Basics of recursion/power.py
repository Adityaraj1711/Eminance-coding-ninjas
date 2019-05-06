def power(x, n):
    if n==1:
        return x
    else:
        return x*power(x,n-1)
    

# Main
from sys import setrecursionlimit
setrecursionlimit(11000)
x, n=list(int(i) for i in input().strip().split(' '))
print(x**n)
