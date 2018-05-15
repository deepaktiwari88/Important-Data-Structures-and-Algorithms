/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void topView(node * root) {
    
    int i;
    
    map<int,int> arr;             // Store position of elements in sorted order
    
    queue<pair<node*,int>> q;     // Used to implement level order traversal
    
    pair<node*,int> temp;
    
    q.push(make_pair(root,0));
    
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        
        if(arr.find(temp.second)==arr.end())          // Check whether a position already covered or not
            arr[temp.second] = temp.first->data;
        
        if(temp.first->left!=NULL)
            q.push(make_pair(temp.first->left, temp.second-1));
        
        if(temp.first->right!=NULL)
            q.push(make_pair(temp.first->right, temp.second+1));    
    }
   
    for(auto i=arr.begin();i!=arr.end();i++)
        cout<<i->second<<" ";
    
    

}
