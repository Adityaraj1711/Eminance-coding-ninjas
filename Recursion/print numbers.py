## Read input as specified in the question.
## Print output as specified in the question.

def rec(t):
    if t==1:
        print(t,end=' ')
        return
    else:
        rec(t-1)
        print(t,end=' ')
        return


t = int(input())

for a in range(t):
    print(a+1,end=' ')
