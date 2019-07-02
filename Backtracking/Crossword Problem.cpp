/*

Crossword Problem
Send Feedback
CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with word list which needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example: The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contains crossword. Each of 10 lines have a character array of size 10. Input characters are either '+' or '-'.
Next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Sample Test Cases:
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA

*/

#include<bits/stdc++.h>
#include<string>

using namespace std;
pair<bool,int> IsVertical(char input[10][10], string name, int n){
    
    pair<bool,int> ans;
    ans.first=false;
     int j=0;
    
    int counter=0;
    
    for(int i=0; i<10; i++){
     
        if(input[i][n]=='-' || input[i][n]== name[j]){
        counter++;
        j++;  
        
        if(counter==name.length()){
            ans.first=true;
            ans.second=i-counter+1;
            break;
        }
         
        }
       
        else{
        counter=0;
        j=0;
    }
        }
    
    return ans;
}
    
    
  pair<bool,int> IsHorizontal(char input[10][10],string name, int n){
    
    pair<bool,int> ans;
    
    ans.first=false;
    
    int j=0;
    
    int counter=0;
    
    for(int i=0; i<10; i++){
    if(input[n][i]=='-' || input[n][i]== name[j] ){
        counter++;
        j++;
        
        if(counter==name.length()){
            ans.first=true;
            ans.second=i-counter+1;
            break;
        }
    }
       
        else{
        counter=0;
        j=0;
    
    } } 
        return ans;
        
}
      
      
        
 void setVertical(char input[10][10], string name, int n, bool helper[10], int start){
     
     for(int i=0; i<name.length(); i++){
        if(input[n][start+i]==name[i]){
             i++;
         }
         input[i+start][n]=name[i];
         helper[i+start]=true;
     }
     
     
 }
        
void setHorizontal(char input[10][10],string name, int n, bool helper[10], int start){
     
     for(int i=0; i<name.length(); i++){
         if(input[n][start+i]==name[i]){
             i++;
         }
         input[n][start+i]=name[i];
         helper[i+start]=true;
     }
     
     
 }
      
      void resetVertical(char input[10][10],bool helper[10], int n){
          for(int i=0; i<10; i++){
              if(helper[i]==true){
                  input[i][n]='-';
                  helper[i]=false;
              }
          }
      }
        
       void resetHorizontal(char input[10][10],bool helper[10], int n){
          for(int i=0; i<10; i++){
              if(helper[i]==true){
                  input[n][i]='-';
                  helper[i]=false;
              }
          }
      }
        
        

       bool crossward(char input[10][10],string* names, int index, int number){
           
           if(index==number){
               return true;
           }
           
           // cout<<index<<number<<" ";
           
           bool helper[10];
           for(int i=0; i<10; i++){
               helper[i]=false;
           }
           
           pair<bool,int> check;
           
           for(int i=0; i<10; i++){
              check=IsVertical(input,names[index],i);
               
               if(check.first==true){
                    
                   setVertical(input,names[index],i,helper,check.second); 
                   if(crossward(input,names,index+1,number)==true){
                       return true;
                   } else{
                       resetVertical(input,helper,i);
                   }
                   
               }
               
           }
           
           
            for(int i=0; i<10; i++){
              check=IsHorizontal(input,names[index],i);
              
                if(check.first==true){
                   
                    setHorizontal(input,names[index],i,helper,check.second);
                         
             if(crossward(input,names,index+1,number)==true){
                       return true;
                   } else{
                       resetHorizontal(input,helper,i);
                   }
                   
               }
                
               }
           
          
           return false;
       }
           
           
             
   


int main() {

	// Write your code here
    
    char input[10][10];
    
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin>>input[i][j];
        }
    }
    
    string names[100];
    
    string input_line;
    
    cin>>input_line;

    int k=0;
    
    for(int i=0; input_line[i]!='\0'; i++){
        if(input_line[i]==';'){
            k++;
            i++;
        }
        names[k]=names[k]+input_line[i];
        }
    
    
     bool help= crossward(input,names,0,k+1);
    
    
      for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout<<input[i][j];
        }
        cout<<endl;
    }    
}
