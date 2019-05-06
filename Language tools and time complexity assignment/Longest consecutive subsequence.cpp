#include<bits/stdc++.h>
using namespace std;


vector<int> longestSubsequence(int *arr, int n){

  unordered_map<int,bool> m;
  for(int i = 0;i<n;i++){
    m[arr[i]] = true;
  }
  
  int count = 0,max = 0,newstart;
  for(int i = 0;i<n;i++){
    if(m[arr[i]]){
      bool begin = true,end = true;
      int b=arr[i],e=arr[i]+1;
      count = 0;
      int start;
      while(begin){
        if(m.count(b)){
          b-=1;
        }
        else {
          begin = false;
        }
      }
      while(end){
        if(m.count(e)){
          e+=1;
        }
        else {
          end = false;
        }
      }
      count = e-b-2;
      start = b+1;
      
      if(count>max){
        max = count;
        newstart = start;
      }
    }
  }
  
  
  vector<int> vc;
  for(int i = newstart;i<=max+newstart;i++){
    //cout<<i<<endl;
    vc.push_back(i);
  }
  if(vc.size()==1){
    vc.pop_back();
    vc.push_back(arr[0]);
  }
  return vc;
}
