#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define MAX 1000005

void swap(int *a,int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
int partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = left-1;

    for(int j=left;j<right;j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[i+1],&arr[right]);
    return i+1;
}

void QuickSort(int arr[],int left,int right)
{
    if(left > right)
        return;

    int p = partition(arr,left,right);

    QuickSort(arr,left,p-1);
    QuickSort(arr,p+1,right);

}
int main()
{
    int N,i,arr[10000];

    cout<<"Enter the size of array\n";
    cin>>N;

    cout<<"Enter the elements\n";

    for(i=0;i<N;i++)
        cin>>arr[i];

    QuickSort(arr,0,N-1);

    cout<<"\nSorted Array\n";

    for(i=0;i<N;i++)
        cout<<arr[i]<<" ";
}

