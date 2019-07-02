/*
Merge Sort Code
Send Feedback
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 1000
Sample Input:
6 
2 6 8 5 4 3
Sample Output:
2 3 4 5 6 8
*/

void merge(int input[], int start, int mid, int end){
    int n1 = mid - start + 1;
    int n2 = end-mid;
    int L[n1];
    int R[n2];
    
    int i = 0;
    int j = 0;
    int k = start;
    for(i = 0; i < n1; i++){
        L[i] = input[k];
        k++;
    }
    for(j = 0; j < n2; j++){
        R[j] = input[k];
        k++;
    }
    i = 0;
    j = 0;
    k = start;
    
    while(i < n1 && j < n2){
        if(L[i]<R[j]){
            input[k] = L[i];
            i++;
            k++;
        } else {
            input[k] = R[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        input[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        input[k] = R[j];
        j++;
        k++;
    }
}


void _mergeSort(int input[], int first, int last){
    if(first >= last){
        return;
    }
    int mid = (first+last)/2;
    _mergeSort(input, first, mid);
    _mergeSort(input, mid + 1, last);
    merge(input, first, mid, last);
}

void mergeSort(int input[], int size){
    _mergeSort(input,0,size-1);
    return;
}

