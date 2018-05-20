#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,rows,cols,arr[500][500];

    cout<<"Enter number of rows\n";
    cin>>rows;

    cout<<"Enter number of columns\n";
    cin>>cols;

    for(i=1;i<=rows;i++)
    {
        cout<<"Enter values in row "<<i+1<<"\n";

        for(j=1;j<=cols;j++)
            cin>>arr[i][j];
    }

    int dp[505][505];
    int largest_size = -1;

    for(i=0;i<rows+1;i++)
    {
        for(j=0;j<cols+1;j++)
        {
            if((i==0) || (j==0))
                dp[i][j]=0;

            dp[i][j] = (arr[i][j]) ? (1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))) : (0);

            if(dp[i][j] > largest_size)
                largest_size = dp[i][j];
        }
    }

    cout<<largest_size<<endl;
}
