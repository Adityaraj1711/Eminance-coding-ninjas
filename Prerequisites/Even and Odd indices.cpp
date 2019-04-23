#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
  	long int even=0,odd=0;
  	long int t;
	cin>>t;
  	int *ar;
  	ar = new int[t];
  	for(int i = 0;i<t;i++){
      cin>>ar[i];
      if(i%2==0){
        if(ar[i]%2==0){
          even += ar[i];
        }
      }
      else{
        if(ar[i]%2!=0){
          odd += ar[i];
        }
      }
    }
  	cout<<even<<" "<<odd;
  return 0;
}