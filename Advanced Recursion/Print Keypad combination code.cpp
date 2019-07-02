/*
Print Keypad Combinations Code
Send Feedback
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
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
*/

#include <iostream>
#include <string>
using namespace std;
string dir[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void print(int num,string output)
{
    if(num==0)
    {
        cout<<output<<endl;
    }
  int recall=num/10;
    int combo=num%10;
     for(int i=0;i<dir[combo].size();i++)
    {
        //dir element to be inserted at the first of output string
         
          print(recall,dir[combo][i]+output);
    
    }
}
void printKeypad(int num){
    string output="";
    print(num,output);
   
    
}



