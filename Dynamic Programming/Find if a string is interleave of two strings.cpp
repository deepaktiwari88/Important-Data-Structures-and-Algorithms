//Problem Link - https://practice.geeksforgeeks.org/problems/interleaved-strings/1

#include<bits/stdc++.h>
using namespace std;

string a,b,c;

int main()
{
    int t,i,j;

    cin>>t;

    while(t--)
    {
        cin>>a>>b>>c;

        int dp[105][105];
        dp[0][0]=1;

        for(i=1;i<=a.size();i++)
        {
            if((c[i-1]==a[i-1]) && (dp[i-1][0]==1))
                dp[i][0]=1;
            else
                dp[i][0]=0;  
        }
        
        for(i=1;i<=b.size();i++)
        {
            if((c[i-1]==b[i-1]) && (dp[0][i-1]==1))
                dp[0][i]=1;
                else
                    dp[0][i]=0;
        }

        for(i=1;i<=a.size();i++)
        {
            for(j=1;j<=b.size();j++)
            {
                if(dp[i][j-1]==1)
                {
                    if(b[i-1]==c[i+j-1])
                        dp[i][j]=1;
                    else
                        dp[i][j]=0;
                }
                if(dp[i-1][j]==1)
                {
                    if(a[i-1]==c[i+j-1])
                        dp[i][j]=1;
                    else
                        dp[i][j]=0;
                }
            }
        }
        cout<<dp[a.size()][b.size()]<<endl;   
    }
}
