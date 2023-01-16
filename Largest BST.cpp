/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
//Same Concept of LargestBST
 class NodeInfo{
     public:
     int maxNode , minNode , maxSize ;
     //initialized
     NodeInfo(int minNode , int maxNode , int maxSize) {
         this->minNode = minNode;
         this->maxNode = maxNode;
         this->maxSize = maxSize;
     }
 };

class Solution{
    public: 
       NodeInfo largestSumBST(Node*root){
       if(!root) {
           return NodeInfo(INT_MAX,INT_MIN,0) ;
       }
       //post order
       NodeInfo leftSum = largestSumBST(root->left);
       NodeInfo rightSum = largestSumBST(root->right);

       //check for bst 
      if(leftSum.maxNode < root->data && root->data<rightSum.minNode){
return NodeInfo(min(root->data,leftSum.minNode)  , max(root->data,rightSum.maxNode) ,leftSum.maxSize + rightSum.maxSize +1);
      }

      return NodeInfo( INT_MIN ,INT_MAX  ,max(leftSum.maxSize , rightSum.maxSize));
   }
         
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
         
           return   largestSumBST(root).maxSize;
    }
};
