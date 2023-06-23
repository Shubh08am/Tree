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
    int height(TreeNode*root){
        if(!root) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    // O(N*N)   //APPROACH-1 
    bool check(TreeNode*root){
        if(!root) return true;
        int lh = height(root->left) ;
        int rh = height(root->right) ;
        if(abs(lh-rh)>1) return 0;
        bool leftcall = check(root->left);
        bool rightcall = check(root->right);
        return leftcall && rightcall;
    }
    //APPROACH-2  O(N)
    int check2(TreeNode*root,bool&ans){
        if(!root || !ans) return 0;

        int lh = check2(root->left,ans);
        int rh = check2(root->right,ans);

        if(abs(lh-rh)>1) ans=false;

        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
     //   return check(root);   //APPROACH-1
           
           bool ans=1;
            check2(root,ans);   //APPROACH-2 
            return ans;
    }
};
