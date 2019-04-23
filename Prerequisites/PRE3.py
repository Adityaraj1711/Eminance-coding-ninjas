t = int(input())
ar = []
sum=0
for a in range(t):
  ar.append(list(map(int,input().split())))

for idx,a in enumerate(ar):
  if(idx==0 or idx==t-1):
    for i in a:
      sum+=i
  else:
    sum+=a[0]
    sum+=a[-1]
    if (2*idx+1==t):
      sum+=a[idx]
    else:
      sum+=a[idx]
      sum+=a[-idx-1]
print(sum)
