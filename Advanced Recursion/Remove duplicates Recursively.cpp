/*
Remove Duplicates Recursively
Send Feedback
Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string
Constraints :
1 <= Length of String S <= 10^3
Sample Input :
aabccba
Sample Output :
abcba
*/

void removeConsecutiveDuplicates(char *input) {
   
    if(input[0] == '\0'){
        return;
    }
    if(input[0]==input[1]){
        int i = 0;
        for(; input[i]!= '\0'; i++){
            input[i] = input[i+1];
        }
        input[i] = '\0';
        removeConsecutiveDuplicates(input);
    }    
    removeConsecutiveDuplicates(input+1);
}
