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
        TreeNode*curr=root;
        stack<TreeNode*>st;
        vector<int>postorder;
        while(curr || !st.empty()){
            if(curr){
                st.push(curr);
                curr=curr->left;
            }
            else{
                TreeNode*temp=st.top()->right;
                if(temp!=NULL) curr=temp;
                if(temp==NULL){
                        temp=st.top();
                        st.pop();
                        postorder.push_back(temp->val);

                        while(!st.empty() && temp==st.top()->right){
                            temp=st.top();
                            st.pop();
                            postorder.push_back(temp->val);
                        }
                }  
            }  
        }
    return postorder;
    }
};
