#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N,i,j,k,carry,temp,remainder;

    cin>>N;

    int arr[500];

    arr[0]=1;
    j=0;

    for(i=1;i<=N;i++)
    {
        int carry=0;

        for(int k=0;k<=j;k++)
        {
            temp = arr[k] * i + carry;
            remainder = temp%10;
            carry = temp/10;

            arr[k] = remainder;
        }

        while(carry!=0)
        {
            arr[++j]=carry%10;
            carry /= 10;
        }
    }
    for(;j>=0;j--)
        cout<<arr[j];

        cout<<endl;
}
