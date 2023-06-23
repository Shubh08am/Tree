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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(!root) return ans;
        q.push(root);
         int order=0;
        while(!q.empty()){
            int sz = q.size();
            int m=sz;
            vector<int>level(sz);
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                int i=(order==0?m-sz-1:sz);
                level[i]=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
        ans.push_back(level);
        order^=1;
        }
    return ans;
    }
};
