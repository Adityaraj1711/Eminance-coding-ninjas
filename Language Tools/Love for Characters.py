t = int(input())
s = input()
A,S,P = 0,0,0
for a in s:
  if a=='a':
    A += 1
  if a=='s':
    S += 1
  if a=='p':
    P +=1
    
print(A,S,P)
