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
    int solve(TreeNode*root,int&sum){
        if(!root) return 0;

        int leftsum = max(0,solve(root->left,sum)) ; 
        int rightsum = max(0,solve(root->right,sum));

        int currsum = root->val+leftsum+rightsum;
        sum = max(sum,currsum) ; 

        return max(leftsum,rightsum)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        solve(root,sum);
        return sum;
    }
};
