#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int P[1001][1001], C[1001];

int main()
{
    int T,N,i;
    
    cin>>T;
    
    while(T--)
    {
        string str;
        
        cin>>str;
        
        N = str.size();
        
        memset(P, 0, 1001*1001*sizeof(int));
        memset(C, 0, sizeof(C));
        
        for(i=0;i<N;i++)
            P[i][i] = 1;
        
        int L,j;
        
        for(L=2;L<=N;L++)
        {
            for(i=0;i<N-L+1;i++)
            {
                j = i+L-1;
                
                if(L==2)
                    P[i][j] = (str[i] == str[j]);
                else
                    if((str[i]==str[j]) && P[i+1][j-1])
                        P[i][j] = 1;
            }
        }
        
        for(i=0;i<N;i++)
        {
            if(P[0][i] == 1)
                C[i] = 0;
            else
            {
            	 C[i] = INT_MAX;
            	 
                for(int k=0;k<i;k++)
                {
                    if(P[k+1][i] && (1+C[k]) < C[i])
                        C[i] = 1+C[k];
                }
            }
        }
        
        cout<<C[N-1]<<endl;
    }

    return 0;
}
