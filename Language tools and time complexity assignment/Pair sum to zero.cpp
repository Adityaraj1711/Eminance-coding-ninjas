#include<bits/stdc++.h>
using namespace std;

void PairSum(int *input, int n){
		/* Don't write main().
     	* the input array is already passed as function argument.
     	* Don't need to return anything. Print the desired pairs in the function itself.
     	*/
      map<int,int> um;
      for(int i = 0;i<n;i++){
        um[input[i]] += 1;
      }

	  map<int,int> :: iterator it;
  	for(it = um.begin();it!=um.end();it++){
      if((*it).first>0)
      if((*it).second>0){
        if(um[0-(*it).first]){
          for(int i = 0;i<((*it).second * um[0-(*it).first]);i++){
            cout<<0-(*it).first<<" "<<(*it).first<<endl;
          }
        }
      }
    }
}
