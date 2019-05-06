#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main() {

  ull t;
  cin>>t;
  while(t--){
    ull val;
    cin>>val;
    ull s = 0;
    while(val!=0){
      s+=val%10;
      val/=10;
    }
    cout<<s<<endl;
  }
  return 0;
}
