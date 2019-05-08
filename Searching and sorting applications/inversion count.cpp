#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

  
ll merge(int arr[], int temp[], int left, int mid, int right) 
{ 
    int i, j, k; 
    ll inv_count = 0; 
  
    i = left;
    j = mid; 
    k = left; 
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
            inv_count = inv_count + (mid - i); 
        } 
    } 
  	while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    while (j <= right) 
        temp[k++] = arr[j++]; 
  	for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 
ll zmergeSort(int arr[], int temp[], int left, int right) 
{ 
    int mid;
    ll inv_count = 0; 
    if (right > left) { 
        mid = (right + left) / 2; 
        inv_count = zmergeSort(arr, temp, left, mid); 
        inv_count += zmergeSort(arr, temp, mid + 1, right); 
        inv_count += merge(arr, temp, left, mid + 1, right); 
    } 
    return inv_count; 
} 


ll mergeSort(int arr[], int array_size) 
{ 
    int* temp = (int*)malloc(sizeof(int) * array_size); 
    return zmergeSort(arr, temp, 0, array_size - 1); 
} 

long long solve(int A[], int n)
{
  return mergeSort(A,n);
}

/*
int main() {
	ll t;
  cin>>t;
  ll arr[t];
  for(ll i = 0;i<t;i++){
    cin>>arr[i];
  }
  ll inv_count = 0;
  inv_count = mergeSort(arr,t);
  cout<<inv_count<<endl;
  return 0;
}*/
