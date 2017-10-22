#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

struct node{
    char character;
    int frequency;
    node* left;
    node* right;
};

map<int,pair<node*,char>> tree;

void Printcodes(node* root,string str)
{
    if(!root)
        return;

    if(root->character!='#')
        cout<<root->character<<" "<<str<<endl;

    Printcodes(root->left, str+"0");
    Printcodes(root->right, str+"1");
}

void CreateTree(map<int,char> mapp)
{
    int lint,rint;
    node *laddress, *raddress;

    for(auto it=mapp.begin();it!=mapp.end();it++)
    {
        node* p = new node;
        p->character = it->second;
        p->left = NULL;
        p->right = NULL;
        p->frequency = it->first;
        tree.insert(mp(it->first,mp(p,it->second)));
    }

    while(tree.size()!=1)
    {
        auto a = tree.begin();
        lint = a->first;
        laddress = a->second.first;
        tree.erase(a);

        auto b = tree.begin();
        rint = b->first;
        raddress = b->second.first;
        tree.erase(b);

        node *p = new node;
        p->character = '#';
        p->frequency = lint + rint;
        p->left = laddress;
        p->right = raddress;

        tree.insert(mp(p->frequency,mp(p,p->character)));
    }
}
int main()
{
    int N,b,i;
    char a;
    map<int,char> mapp;

    cout<<"Enter total number of characters\n";
    cin>>N;

    cout<<"Enter characters and their frequencies\n";

    for(i=0;i<N;i++)
    {
        cin>>a>>b;
        mapp.insert(mp(b,a));
    }

    CreateTree(mapp);

    node* root = tree.begin()->second.first;
    string str = "";
    Printcodes(root,str);
}
