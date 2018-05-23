//Problem Link - https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1

/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; 
*/

// Should set the nextRight for all nodes

void connect(Node *p)
{
   queue<pair<Node*, int>> Q;
   Q.push(make_pair(p,0));
   
   Node* pnode = NULL;
   int plevel=-1;
   
   while(!Q.empty())
   {
       Node* node = Q.front().first;
       int level = Q.front().second;
       
       Q.pop();
       
       if(node)
       {
           if(pnode)
           {
                if(plevel==level)
                    pnode->nextRight = node;
                else 
                    pnode->nextRight = NULL;
           }
           else
                node->nextRight = NULL;

           pnode = node;
           plevel = level;
           
           if(node->left!=NULL)
           Q.push(make_pair(node->left, level+1));
           
           if(node->right!=NULL)
           Q.push(make_pair(node->right, level+1));
       }
   }
   
   pnode->nextRight=NULL;
}
