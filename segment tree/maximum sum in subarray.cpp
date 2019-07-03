/*
Maximum Sum In Subarray
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| = 15007 , 1 = N = 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x = i = j = y }.
Given M queries, your program must output the results of these queries.
Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one 
query per line.
Sample Input:
3 
-1 2 3 
1
1 2
Sample Output:
2
*/

#include <bits/stdc++.h>
using namespace std;

struct node {
    long long int sum, prefixsum, suffixsum, maxsum;
};

node tree[1000100];
long long int arr[5000100];

void build(int index, int start, int end)
{

    if (start == end) {

        tree[index].sum = arr[start];
        tree[index].prefixsum = arr[start];
        tree[index].suffixsum = arr[start];
        tree[index].maxsum = arr[start];
    }
    else if(start>end) return ;
    else {
        int mid = (start + end) / 2;
        build(2 * index, start, mid);
        build(2 * index + 1, mid + 1, end);

        tree[index].prefixsum = max(tree[2 * index].prefixsum, tree[2 * index].sum + tree[2 * index + 1].prefixsum);
        tree[index].suffixsum = max(tree[2 * index + 1].suffixsum, tree[2 * index + 1].sum + tree[2 * index].suffixsum);
        tree[index].sum = tree[2 * index].sum + tree[2 * index + 1].sum;
        tree[index].maxsum = max(tree[2*index].maxsum, max(tree[2 * index + 1].maxsum, tree[2 * index].suffixsum + tree[2 * index + 1].prefixsum));

        // tree[index].maxsum = max(tree[index].prefixsum,
        //     max(tree[index].suffixsum,
        //                              max(tree[2 * index + 1].maxsum,
        //                                  max(tree[2 * index + 2].maxsum,
        //                                      tree[2 * index + 1].suffixsum + tree[2 * index + 1].suffixsum
        //                                          + tree[2 * index + 2].prefixsum))));
    }
}

node query(int index, int start, int end, int l, int r)
{
    node result;
    result.sum = result.prefixsum = INT_MIN;
    result.suffixsum = result.maxsum = INT_MIN;
    if (start > end || start > r || end < l){
        return result;
    }

    if (l <= start && end <= r)
        return tree[index];

    int mid = (start + end) / 2;
    // if (l > mid)
        // return query(2 * index + 2, mid + 1, end, l, r);
    // if (r <= mid)
        // return query(2 * index + 1, start, mid, l, r);

    node left = query(2 * index, start, mid, l, r);
    node right = query(2 * index + 1, mid + 1, end, l, r);

    result.prefixsum = max(left.prefixsum, left.sum + right.prefixsum);
    result.suffixsum = max(right.suffixsum, right.sum + left.suffixsum);
    result.sum = left.sum + right.sum;
    result.maxsum=max(left.maxsum,max(right.maxsum,left.suffixsum+right.prefixsum));

    // result.maxsum = max(result.prefixsum,
    //     max(result.suffixsum,
    //                         max(left.maxsum,
    //                             max(right.maxsum,
    //                                 left.suffixsum + right.prefixsum))));
    return result;
}

int main()
{
    long long int n, m, a, b;
    scanf("%lld", &n);
    // cin>>n;
    for (int i = 0; i < n; ++i)
        scanf("%lld", &arr[i]);

    build(1, 0, n - 1);
    scanf("%d", &m);

    for (int i = 0; i < m; ++i) {
        scanf("%lld%lld", &a, &b);
        // cin>>a>>b;
        printf("%lld\n", query(1, 0, n - 1, a - 1, b - 1).maxsum);
        
    }
    return 0;
}

