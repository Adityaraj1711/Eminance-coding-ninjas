// arr - input array
// size - size of array
// d - array to be rotated by d elements

void Rotate(int arr[], int d, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing the output is handled automatically.
     */
  int ar[size];
  int j = 0;
  for(int i = d ;i<size;i++){
    ar[j] = arr[i];
    j++;
  }
  for(int i = 0;i<d;i++){
    ar[j] = arr[i];
    j++;
  }
  
  for(int i = 0;i<size;i++){
    arr[i] = ar[i];
    //cout<<ar[i]<<" ";
   // printf("%d ",ar[i]);
  }
  
  
}	

