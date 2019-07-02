/*
Quick Sort Code
Send Feedback
Sort an array A using Quick Sort.
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

void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int input[], int low, int high){
    int pivot = input[high];
    int i = low-1;
    for(int j = low; j<=high-1; j++){
        if(input[j] <= pivot ){
            i++;
            swap(&input[i], &input[j]);
        }
    }
    swap(&input[i+1], &input[high]);
    return i+1;
}

void _quickSort(int input[], int start, int end){
    if(start<end){
        int pi = partition(input, start, end);
        _quickSort(input, start, pi -1);
        _quickSort(input, pi+1, end); 
    }
}


void quickSort(int input[], int size) {
    _quickSort(input, 0, size-1);
}

