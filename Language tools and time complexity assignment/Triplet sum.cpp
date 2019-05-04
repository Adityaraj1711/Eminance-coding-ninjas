// arr - input array
// size - size of array
// x - sum of triplets

void FindTriplet(int arr[], int size, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
  
  for(int i = 0;i<size;i++){
    for(int j = i;j<size;j++){
      if(arr[i]>arr[j]){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  
  for(int i = 0;i<size;i++){
    for(int j = i;j<size;j++){
      for(int k = j;k<size;k++){
        if(arr[i]+arr[j]+arr[k]==x && (i!=j && j!=k && i!=k)){
          cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
        }
      }
    }
  }
return;
}

