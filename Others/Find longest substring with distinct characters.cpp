#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int T,N,i;

    cin>>T;

    while(T--)
    {
        string str;

        cin>>str;

        int hash[26]={0};
        int j, start = 0, ans = INT_MIN;

        for(i=0, j=0; i<str.size(); i++)
        {
            for(;j<str.size();j++)
            {
                if(hash[str[j]-'a']==1)
                {
                    while(str[i]!=str[j]){
                        hash[str[i]-'a'] = 0;
                        i++;
                    }
                    
                    hash[str[i]-'a'] = 0;
                    i++;

                }

                hash[str[j]-'a'] = 1;

                ans = max(ans, j-i+1);
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
