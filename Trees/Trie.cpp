#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
};

TrieNode* getNode()
{
    TrieNode* pNode = new TrieNode;
    pNode->isEnd = false;
    
    for(int i=0;i<26;i++)
        pNode->children[i]=NULL;
}

void InsertTrie(TrieNode* root, string str)
{
    TrieNode* crawl=root;
    
    for(int i=0;i<str.size();i++)
    {
        int index = str[i]-'a';
        
        if(crawl->children[index]==NULL)
            crawl->children[index] = getNode();
            
        crawl = crawl->children[index];
    }
    
    crawl->isEnd = true;
}

bool searchTrie(TrieNode* root, string str)
{
    TrieNode* crawl=root;
    
    for(int i=0;i<str.size();i++)
    {
        int index = str[i]-'a';
        
        if(crawl->children[index]==NULL)
            return false;
            
        crawl = crawl->children[index];
    }
    
    return (crawl!=NULL && crawl->isEnd);
}

int main()
{
    int T,N,i;
    
    cin>>T;
    
    while(T--)
    {
        cin>>N;
        
        TrieNode* root = getNode();
        
        string str;
        
        for(i=0;i<N;i++)
        {
            cin>>str;
            InsertTrie(root, str);
        }
        
        cin>>str;
        
        cout<<searchTrie(root,str)<<endl;
        
    }
    return 0;
}
