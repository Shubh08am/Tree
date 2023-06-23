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
     int depth(TreeNode*root){
        if(root==NULL) return 0 ; 
        int lh = depth(root->left) ; 
        int rh = depth(root->right) ; 
        //reached leaf node
        if(lh==0 || rh==0) return 1+lh+rh;
        return 1+min(lh,rh);
    }
    int minDepth(TreeNode* root) {
        return depth(root);
    }
};
