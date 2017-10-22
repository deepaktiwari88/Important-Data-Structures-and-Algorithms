#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define MAX 100005

int parent[MAX];
pair <int,pair<int,int>> edges[MAX];
int E,i,a,b,weight,cost;

void pre()
{
    for(i=0;i<=MAX;i++)
        parent[i]=i;
}

int root(int x)
{
    while(parent[x]!=x)
    {
        parent[x]=parent[parent[x]];
        x = parent[x];
    }
    return x;
}
int kruskal()
{
    int mincost = 0,roota,rootb,i;

    for(i=0;i<E;i++)
    {
        roota = root(edges[i].second.first);
        rootb = root(edges[i].second.second);

        if(roota!=rootb)
        {
            mincost += edges[i].first;
            parent[roota] = parent[rootb];
        }
    }

    return mincost;
}
int main()
{
    pre();
        
    cout<<"Enter the number of edges\n";
    cin>>E;

    for(i=0;i<E;i++)
    {
        cout<<"Enter the vertices between which edge exists and weight of edge"<<endl;
        cin>>a>>b>>weight;
        edges[i] = mp(weight,mp(a,b));
    }

    sort(edges,edges+E);

    cost = kruskal();
    cout<<cost<<endl;
}
