#include<bits/stdc++.h>

using namespace std;

void heapify(int arr[], int i, int N)
{
    int left,right,j,temp;

    left=2*i+1;
    right=2*i+2;

    if(left<N && arr[left] > arr[i])
        j=left;
    else
        j=i;

    if(right<N && arr[right] > arr[i])
        j=right;

    if(j!=i)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;

        heapify(arr,j,N);
    }
}
int main()
{
    int i,N;
    int arr[]={6,7,1,2,3,4,8};    // Take input array according to your choice
    N=7;

    for(i=N/2;i>=0;i--)
        heapify(arr,i,N);

    for(i=0;i<N;i++)
        cout<<arr[i]<<endl;
}
