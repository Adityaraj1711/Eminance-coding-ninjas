#include <algorithm>
void FindTriplet(int *input,int size, int x) {
    sort(input,input+size);
    for(int i=0;i<size;i++) {
        int st=i+1; int end=size-1; 
        int val=x-input[i]; 
        while(st<end){ 
            if(input[st]+input[end] > val) 
            end--; 
            else
            if(input[st]+input[end]<val)
            st++;
            else {
                int count1=0,count2=0; 
                for(int ptr=st;ptr<=end;ptr++) { 
                    if(input[ptr] == input[st]) count1++; 
                    else
                    break; 
                    
                } 
                for(int ptr= end;ptr>=st;ptr--) { 
                    if(input[ptr] == input[end]) 
                    count2++;
                    else 
                    break;
                }
                int combinations = count1*count2;
                if(input[st] == input[end])
                    combinations = ((end-st+1)*(end-st))/2;
                    for(int k=0;k<combinations;k++) { 
                        cout<<input[i] << " "<<input[st]<<" "<<input[end]<<endl;
                    }
                    st=st +count1; 
                    end=end - count2; 
                
            }
        }
    }
}
