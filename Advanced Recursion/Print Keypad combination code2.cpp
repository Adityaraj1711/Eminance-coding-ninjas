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


string getString(int n){
  if(n==1){
    return "";
  }
  if(n==2){
    return "abc";
  }
  if(n==3){
    return "def";
  }
  if(n==4){
    return "ghi";
  }
  if(n==5){
    return "jkl";
  }
  if(n==6){
    return "mno";
  }
  if(n==7){
    return "pqrs";
  }
  if(n==8){
    return "tuv";
  }
  if(n==9){
    return "wxyz";
  }
}

void printkeypadUtil(int num,string output){
  if(num==0){
    cout<<output<<endl;
    return;
  }
  int smallNum = num/10;
  int remainder = num%10;
  string option = getString(remainder);
  for(int i = 0;i<option.length();i++){
//    printkeypadUtil(smallNum,output);
    printkeypadUtil(smallNum,option[i] + output);
  }
}

void printKeypad(int num){
  printkeypadUtil(num,"");
}





