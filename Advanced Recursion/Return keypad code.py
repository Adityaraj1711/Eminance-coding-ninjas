'''
Return Keypad Code
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : The order of strings are not important.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
'''

def keypad(n):
  opt = ["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
  if(n==0):
    lst = [""]
    return lst
  
  small = n//10
  remainder = n%10
  lst = keypad(small)
  lstlen = len(lst)
  optionlen = len(opt[remainder])
  lst *= optionlen
  k = 0
  for i in range(0,optionlen):
    for j in range(0,lstlen):
      lst[k] = lst[k] + opt[remainder][i]
      k+=1
  return lst


t = int(input())
print(t)
l = keypad(t)

for a in l:
  print(a)
