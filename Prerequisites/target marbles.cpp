#include<bits/stdc++.h>
using namespace std;

void printing(int ar[],int i, int j){
  cout<<"true"<<endl;
  for(int x = i;x<=j;x++ ){
    cout<<ar[x]<<" ";
  }
  return;
}

int main() {
  long n,s;
  cin>>n>>s;
  int ar[n];
  for(int i = 0;i<n;i++){
   cin>>ar[i]; 
  }
  bool flag = false;
  for(int i = 0; i<n;i++){
    int sum = 0;
    for(int j = i;j<n;j++){
      sum += ar[j];
      if(sum==s){
        printing(ar,i,j);
        flag = true;
        break;
      }
      else if(sum>s){
        break;
      }
    }
    if(flag){
      break;
    }
  }
  if (!flag){
    cout<<"false";
  }
  return 0;
}
