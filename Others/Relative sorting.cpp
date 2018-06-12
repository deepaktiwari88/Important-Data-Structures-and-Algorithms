//Problem Link - https://practice.geeksforgeeks.org/problems/relative-sorting/0

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int bs(int arr[], int low, int high, int key)
{
    int mid;
    
    while(low <= high)
    {
        mid = (low+high)/2;
        
        if(arr[mid]==key)
        {
            if(mid==0)
                return mid;
            else
                if(arr[mid]!=arr[mid-1])
                    return mid;
        }
        
        if(arr[mid]>=key)
            high = mid-1;
        else
            low = mid+1;
    }
    
    return -1;
}
int main()
{
    int T,N,i,M;
    
    int arr1[100], arr2[100];
    
    cin>>T;
    
    while(T--)
    {
        cin>>M>>N;
        
        for(i=0;i<M;i++)
            cin>>arr1[i];
        
        for(i=0;i<N;i++)
            cin>>arr2[i];
            
        sort(arr1, arr1+M);
        
        int hash[100]={0};
        
        for(i=0;i<N;i++)
        {
            int index = bs(arr1,0,M-1,arr2[i]);
            
            if(index!=-1)
            {
                int z=index;
                
                while(arr1[index]==arr2[i])
                {
                    cout<<arr1[index]<<" ";
                    hash[index]=1;
                    ++index;
                }
            }
        }
        
        for(i=0;i<M;i++)
        {
            if(!hash[i])
                cout<<arr1[i]<<" ";
        }
        
        cout<<endl;
    }
    return 0;
}
