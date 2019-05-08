#include<iostream>
using namespace std;
#include<algorithm>
int main()
 {
    long long int  t;
    cin>>t;
    while(t--)
     {
      long long int  n,c;
        cin>>n>>c;
        long long int  arr[n+5];
        for(long long int  i=0;i<n;i++)
         {
          cin>>arr[i];
         }
         sort(arr,arr+n);
    long long int  hi=arr[n-1];
    long long int  lo=arr[0];   
    long long int  mid;
        int ans=-1;
        while(lo<hi)
         {
          long long int  taken=1;
          long long int  last_pos=0;
               mid=(lo+hi)/2;
                  //cout<<"mid "<<mid<<endl;
          	for(long long int  i=1;i<n;i++)//  n-1
           	  {
                if(arr[i]-arr[last_pos]>=mid)
                 {
                  taken++;
                  if(taken==c) break;
                  last_pos=i;
                 }
               }
             //  cout<<"taken "<<taken<<endl;
              
               if(taken<c)
                {
                 hi=mid;
                }
                else
                {
                 
                 lo=mid+1;
                }
                if(taken==c && mid>ans)
                 {
                  ans=mid;
                 }
         }
         cout<<ans<<endl;
        
     }
     return 0;
 }
