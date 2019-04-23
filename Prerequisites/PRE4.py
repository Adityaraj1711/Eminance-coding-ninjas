t = int(input())
ar = list(map(int,input().split()))
for a in range(t//2):
  sum = ar[a]+ar[-a-1]
  print(sum//10,sum%10)
    
