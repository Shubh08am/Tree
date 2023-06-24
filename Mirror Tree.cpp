// function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    Node* solve(Node* node){
        if(!node) return NULL;
        
        Node*p = node->left ; 
        node->left=node->right;
        node->right=p;
        solve(node->left) ; 
        solve(node->right) ; 
        
    }
    void mirror(Node* node) {
       // solve(node); //Approach-1
       //Approach-2
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node*p=q.front();
            q.pop();
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
            
            Node*qp=p->left;
            p->left=p->right;
            p->right=qp;
        }
    }
};
