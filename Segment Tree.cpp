#include<bits/stdc++.h>

using namespace std;

int arr[]={1,2,3,4,5,6,7,8}; //Change this array accordingly

void build(int tree[],int node,int start,int end)
{
    if(start==end)
    {
        tree[node]=arr[start];
        return;
    }

    int mid=(start+end)/2;

    build(tree,2*node+1,start,mid);
    build(tree,2*node+2,mid+1,end);

    tree[node]=tree[2*node+1] + tree[2*node+2];
}

int getsum(int tree[],int start,int end, int l, int r, int node)
{
    if(r<start || l>end)
        return 0;
    if( l<= start && r>= end)
    {
        //cout<<tree[node];
        return tree[node];
    }

    int mid=(start+end)/2;

    return getsum(tree,start,mid,l,r,2*node+1) + getsum(tree,mid+1,end,l,r,2*node+2);
}

void update(int tree[],int start,int end, int idx, int node,int num)
{
    if(start==end)
    {
        arr[idx]=num;
        tree[node]=num;
    }
    else{
    int mid=(start+end)/2;

    if(start<=idx && idx<=mid)
    update(tree,start,mid,idx,2*node+1,num);
    else
    update(tree,mid+1,end,idx,2*node+2,num);

    tree[node] = tree[2*node+1] + tree[2*node+2];
    }
}

int main()
{
    int tree[500]={0};
    
    build(tree,0,0,7);

    /*for(int i=0;i<100;i++)        //Uncomment this to view the segment tree
        cout<<tree[i]<<" ";*/

    cout<<getsum(tree,0,7,0,4,0)<<endl;

    update(tree,0,7,1,0,10766);

    cout<<getsum(tree,0,7,0,4,0)<<endl;

}
