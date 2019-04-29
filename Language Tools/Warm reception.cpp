#include<bits/stdc++.h>
using namespace std;

struct interval{
  long st;
  long et;
};

int main() {
  long t;
  cin>>t;
  long counter = 0;
  interval ar[t];
  for(long i = 0;i<t;i++){
    cin>>ar[i].st;
  }
  for(long i = 0;i<t;i++){
    cin>>ar[i].et;
  }
  long max = 0;
  for(long i = 0;i<2400;i++){
    for(long j = 0;j<t;j++){
      if(i==ar[j].st){
        counter++;
        if(max<counter){
          max = counter;
        }
      }
    }
    for(long j = 0;j<t;j++){
      if(i==ar[j].et){
        counter--;
        if(max<counter){
          max = counter;
        }
      }
    }
  }
  
  cout<<max;
    

  return 0;
}
