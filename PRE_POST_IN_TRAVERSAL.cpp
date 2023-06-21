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
    vector<int> preorderTraversal(TreeNode* root) {
       //all traversal 
       //1 represents preorder 
       //2 represents inorder
       //3 represents postorder
        
      vector<int>preorder,postorder,inorder;

       stack<pair<TreeNode*,int>>st;
       if(!root) return preorder; 
       st.push({root,1});
       while(!st.empty()){
           auto node = st.top() ; 
           st.pop() ; 
            //preorder
           if(node.second==1){
               preorder.push_back(node.first->val);
               node.second++;
               st.push(node);

               if(node.first->left) st.push({node.first->left,1}) ;
           }
           //inorder
          else if(node.second==2){
               inorder.push_back(node.first->val);
               node.second++;
               st.push(node);

               if(node.first->right) st.push({node.first->right,1}) ;
           }
           //postorder
         else  if(node.second==3){
               postorder.push_back(node.first->val);
           }
       }
    return preorder;
    }
};
