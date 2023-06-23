/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL ; 
        //if i get p i will return it 
        if(root==p) return p ;
        //if i get q i will return it 
        if(root==q) return q ;
 
      //make left call 
      TreeNode*leftcall = lowestCommonAncestor(root->left,p,q) ; 
      //make right call 
     TreeNode*rightcall = lowestCommonAncestor(root->right,p,q) ;

         //if at a node both leftcall and rightcall returned NULL--> return NULL
         if(leftcall==NULL and rightcall==NULL)  return NULL ; 


         //if at a node leftcall returns found node and rightcall returned NULL--> return leftcall
         if(leftcall!=NULL and rightcall==NULL)  return leftcall ; 

      //if at a node leftcall returned NULL and rightcall returned found node--> return rightcall
         if(leftcall==NULL and rightcall!=NULL)  return rightcall ; 

      //if at a node both leftcall and rightcall returned found node--> return current node
         if(leftcall!=NULL and rightcall!=NULL)  return root ;

      return root;
    }
};
