#include<iostream>
#include<climits>

#define ll long long

using namespace std;

ll count(int a[],int l,int mid,int r){
	int c[r-l+1];
	int ci=0,i = l,j=mid+1;
	ll sum =0;
	while(i <= mid && j<= r){
		if(a[i] < a[j]){
			sum += (ll)((ll)(r-j+1)*(ll)a[i]);
			c[ci++] = a[i];
			i++;
		}
		else{
			c[ci++] = a[j];
			j++;
		}
	}
	while(i<=mid){
		c[ci++] = a[i++];
	}
	while(j <= r){
		c[ci++] = a[j++];
	}
	for(int i=0;i<ci;i++){
		a[l+i] = c[i];
	}
	return sum;
}

ll murder(int a[],int l,int r){
	if(l < r){
		int mid = (l+r)/2;
		ll x = murder(a,l,mid);
		ll y = murder(a,mid+1,r);
		ll z = count(a,l,mid,r);
		return x+y+z;
	}
	return 0;
}

int main(){

  int T;
  cin>>T;
  while(T--){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<murder(a,0,n-1)<<"\n";
  }
return 0;
}
