
s = input()
ar = []
for a in s:
    if a not in ar:
        ar.append(a)
s = ''
for a in ar:
    s+=a

print(s)
