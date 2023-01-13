

/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void successor(Node*root , int key , Node* &suc){
   // Node*suc=NULL;
    while(root){
        if(root->key> key) {
            suc=root;
            root=root->left;
        }
        else if(root->key<=key){
            root=root->right;
        }
    }
   // return suc;
}

void predecessor(Node*root , int key , Node* &pre){
   // Node*pre=NULL;
    while(root){
        if(root->key>=key) {
             root=root->left;
        }
        else if(root->key<key){
            pre=root;
            root=root->right;
        }
    }
   // return pre;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
 successor(root,key,suc);
 predecessor(root,key,pre);
}
