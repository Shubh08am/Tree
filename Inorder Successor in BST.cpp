/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node*successor = NULL;
        while(root){
            if(root->data>x->data){
                successor=root;
                root=root->left;
            }
        else  if(root->data <= x->data){
               
                root=root->right;
            }
        }
        return successor;
    }
};
