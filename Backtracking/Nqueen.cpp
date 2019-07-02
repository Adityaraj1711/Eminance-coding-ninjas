/*

N-Queen Problem
Send Feedback
Fill The Matrix
A matrix B (consisting of integers) of dimension N × N is said to be good if there exists an array A (consisting of integers) such that B[i][j] = |A[i] - A[j]|, where |x| denotes absolute value of integer x.

You are given a partially filled matrix B of dimension N × N. Q of the entries of this matrix are filled by either 0 or 1. You have to identify whether it is possible to fill the remaining entries of matrix B (the entries can be filled by any integer, not necessarily by 0 or 1) such that the resulting fully filled matrix B is good.
Input
The first line of the input contains an integer T denoting the number of test cases.

The first line of each test case contains two space separated integers N, Q.

Each of the next Q lines contain three space separated integers i, j, val, which means that B[i][j] is filled with value val.
Output
For each test case, output "yes" or "no" (without quotes) in a single line corresponding to the answer of the problem.
Constraints
1 = T = 10^6
2 = N = 10^5
1 = Q = 10^6
1 = i, j = N
0 = val = 1
Sum of each of N, Q over all test cases doesn't exceed 106
Input
4
2 2
1 1 0
1 2 1
2 3
1 1 0
1 2 1
2 1 0
3 2
2 2 0
2 3 1
3 3
1 2 1
2 3 1
1 3 1
Output
yes
no
yes
no

*/

#include <stdio.h>
using namespace std;

#define L 1000000

int arr[L + 5], size[L + 5], H[L + 5];

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
        size[i] = 1;
        H[i] = 0;
    }
}

int root(int i)
{
    while (i != arr[i]) i = arr[i];
    return(i);
}

int calc(int i)
{
    int res = 0;
    while (i != arr[i])
    {
        res ^= H[i];
        i = arr[i];
    }
    return(res);
}

void uni(int ri, int rj, int val)
{
    if (size[ri] <= size[rj])
    {
        arr[ri] = rj;
        size[rj] += size[ri];
        H[ri] = val;
    }
    else
    {
        arr[rj] = ri;
        size[ri] += size[rj];
        H[rj] = val;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        int N, Q;
        scanf("%d %d", &N, &Q);
        init(N);
        bool ok = true;
        for (int k = 0; k < Q; k++)
        {
            int i, j, val;
            scanf("%d %d %d", &i, &j, &val);
            int ri = root(i), rj = root(j), ci = calc(i), cj = calc(j);
            if (ri == rj)
            {
                if (ci ^ cj ^ val) ok = false;
            }
            else uni(ri, rj, ci ^ cj ^ val);
        }
        if (ok) printf("yes\n");
        else printf("no\n");
    }
    return(0);
}    
