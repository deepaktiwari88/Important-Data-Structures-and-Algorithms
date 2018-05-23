#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,N,i;
    cin>>T;

    while(T--){

        string str;
        cin>>str;

        stack<int> s;

        s.push(-1);
        int maxx=0;

        for(i=0;i<str.size();i++)
        {
            if(str[i]=='(')
                s.push(i);
            
            else
            {
                s.pop();

                if(!s.empty())
                    maxx = max(maxx, i-s.top());
                else
                    s.push(i);   
            }
        }
        cout<<maxx<<endl;
    }
}
