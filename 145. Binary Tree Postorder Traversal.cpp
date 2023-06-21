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
    vector<int> postorderTraversal(TreeNode* root) {
        //iterative using two stack 
        //Not At All Intutive 
        stack<TreeNode*>st1,st2;
        vector<int>postorder;
        if(!root) return postorder;
        st1.push(root);

        while(!st1.empty()){
            TreeNode*node=st1.top();
            st1.pop();
            st2.push(node);

            if(node->left) st1.push(node->left); 
            if(node->right) st1.push(node->right);
        }

        //st2 stores post order now 
        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
    return postorder;
    }
};
