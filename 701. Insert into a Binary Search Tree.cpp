/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode*recursion(TreeNode* root, int val){
       if(!root) return new TreeNode(val) ; 
       if(root->val<val) root->right = recursion(root->right,val);
       if(root->val>val) root->left = recursion(root->left,val);
    return root ; 
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
    //  return recursion(root,val); 

    //ITERATIVE APPROACH 
        if(!root) return new TreeNode(val) ; 

        TreeNode*curr = root; 

        while(1){
            if(curr->val<val){
                if(!curr->right){
                    curr->right=new TreeNode(val);
                    break;
                }
                else curr=curr->right;
            }
            if(curr->val>val){
                if(!curr->left){
                    curr->left=new TreeNode(val);
                    break;
                }
                else curr=curr->left;
            }
        }
    return root;
    }
};
