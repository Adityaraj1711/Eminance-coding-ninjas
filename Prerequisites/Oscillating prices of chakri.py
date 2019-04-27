t = int(input())
ar = list(map(int,input().split()))
s = 0
for a in range(len(ar)):
  for b in range(a,len(ar)):
    if(s<(ar[b]-ar[a])):
      s = ar[b]-ar[a]

print(s)
