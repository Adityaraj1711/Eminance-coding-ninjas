#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  getline(cin,s);
  long start = 0;
  map<string,int> m;
  for(int i = 0;i<s.length();i++){
    //cout<<s[i]<<" ";
    if (s[i]==' '){
      string word = s.substr(start,i);
      start = i+1;
      m[word]++;
    }
  }
  string wordl = s.substr(start,s.length()-1);
  m[wordl]++;
  map<string,int> :: iterator it;
  for(it = m.begin();it!=m.end();it++){
  	cout<<(*it).first<<" a "<<endl;
	}
  /*
  for(it = m.begin();it!=m.end();it++){
    if((*it).second>1){
      cout<<(*it).first<<" "<<(*it).second<<endl;
    }
  }
  */
  return 0;
}

