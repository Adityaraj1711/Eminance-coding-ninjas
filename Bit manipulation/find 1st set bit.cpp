/*
Find first set bit
Send Feedback
You are given an integer N. You need to return an integer M, in which only one bit is set which at position of lowest set bit of N (from right to left).
Input Format :
Integer N
Output Format :
Integer M
Sample Input 1 :
7
Sample Output 1 :
1
Sample Input 2 :
12
Sample Output 2 :
4
*/

int returnFirstSetBit(int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    for(int i=0;i<=32;i++){
        if((n&(1<<i))==(1<<i)){
            if(i and not(i & (i-1)))
                return i+1;
        }
    }
    return 0;
}


