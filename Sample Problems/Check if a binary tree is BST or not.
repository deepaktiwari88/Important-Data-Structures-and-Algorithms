/*
The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

bool isSmall(Node* root,int value)
{
    if(root==NULL)
        return true;

    if(root->data < value && isSmall(root->left, value) && isSmall(root->right, value))
        return true;
    else
        return false;
}

bool isLarge(Node* root,int value)
{
    if(root==NULL)
        return true;

    if(root->data > value && isLarge(root->left, value) && isLarge(root->right, value))
        return true;
    else
        return false;
}
    
bool checkBST(Node* root) {

      if(root==NULL)
          return true;

      if(isSmall(root->left, root->data) && isLarge(root->right, root->data) && checkBST(root->left) && checkBST(root->right))
          return true;
      else
          return false;
}
