// Given an array initialised to {0}, you are given Q queries with intervals L and R ( 0 <= L <= R <= N )  and you are supposed to update  
// that interval by increasing value of every element in that interval by 1


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,Q,i,hash[100]={0},L,R;
    
    cout<<"Enter number of queries\n";
    
    cin>>Q;

    while(Q--)
    {
        cout<<"Enter interval for which array values need to be increased by one.\n";
        cin>>L>>R;

        hash[L-1]++;            // This is the main step
        hash[R]--;              // This is the main step
    }

    int arr[100]={0};

    int val=0;

    for(i=0;i<100;i++)
    {
        arr[i]=val;
        val += hash[i];
    }

    for(i=0;i<100;i++)
        cout<<arr[i]<<" ";
}
