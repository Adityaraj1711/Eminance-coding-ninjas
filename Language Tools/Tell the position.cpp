#include<bits/stdc++.h>
using namespace std;
class sort_map
{
  public:
	string key;
	int val;
}sm;

bool Sort_by(const sort_map& a ,const sort_map& b)
{
	return a.val > b.val;
}
int main()
{
  long t;
  map<string,int> d;
  cin>>t;
  for(long i = 0;i<t;i++){
    string temp;
    cin>>temp;
    int s1,s2,s3;
    cin>>s1>>s2>>s3;
    int s = s1+s2+s3;
    d[temp] = s;
  }
	vector< sort_map > v;
	vector< sort_map >::iterator itv;
 	map<string,int> :: iterator it;
  for (it = d.begin(); it != d.end(); ++it)
	{
		sm.key = (*it).first; sm.val = (*it).second;
		v.push_back(sm);
	}
//	for (itv = v.begin(); itv != v.end(); ++itv)
//	{
//	//	cout << (*itv).key << " : " << (*itv).val << endl;
//	}
//	
	sort(v.begin(),v.end(),Sort_by);
	
//	cout << "sorted" << endl;
	long f = 0;
	for (itv = v.begin(); itv != v.end(); ++itv)
	{
//		cout << (*itv).key << " : " << (*itv).val << endl;
      cout << f+1<<" "<<(*itv).key<< endl;
      f++;
	}
	
  return 0;
}

