#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;

    cin>>str;

    long int check=0,i;

    for(i=0;i<str.size();i++)
    {
        if( ( (1<<int(str[i]-'a')) & check) > 0)
            break;
        else
            check |=  (1<<int(str[i]-'a'));
    }

    if(i==str.size())
        cout<<"yes";
    else
        cout<<"no";
}
