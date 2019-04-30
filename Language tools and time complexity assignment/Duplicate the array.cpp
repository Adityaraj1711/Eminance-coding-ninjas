// arr - input array
// size - size of array

int MissingNumber(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int ar[size] = {0};
  for(int i = 0;i<size;i++){
    int z = arr[i];
    ar[z]+=1;
  }
  for(int i = 0;i<size;i++){
    if(ar[i]>1){
      return i;
    }
  }
	return 0;
}

