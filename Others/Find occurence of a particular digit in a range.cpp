#include<bits/stdc++.h>
using namespace std;

int V[100005][11], sum[100005][11];

// Pre-Computation Function to calculate digits for every number within the given constraints
// V stores the digit-wise count for a given number
// sum stores the prefix sum for array V.

void pre()
{
    for(int i=1;i<=100000;i++)
    {
        int temp=i;

        while(temp){

            V[i][temp%10]++;
            temp/=10;
        }
    }

    for(int i=0;i<10;i++)
    {
        sum[0][i]=0;
        sum[1][i]=V[1][i];

        for(int j=2;j<=100000;j++)
            sum[j][i] = sum[j-1][i] + V[j][i];
    }
}

int main()
{
    memset(V, 0, 100005*11*sizeof(int));
    pre();

    int i,j;

    int start, end, digit, queries;

    cin>>queries;

    while(queries--)
    {
        cin>>start>>end>>digit;

        cout<<sum[end][digit] - sum[start-1][digit]<<endl;
    }

}
