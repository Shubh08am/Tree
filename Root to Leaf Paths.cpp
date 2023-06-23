/* Structure of Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/

/* The function should print all the paths from root
 to leaf nodes of the binary tree */
 void solve(Node*root,vector<vector<int>>&ans,vector<int>&v){
     v.push_back(root->data);
     if(!root) return;
     if(!root->left && !root->right){
         ans.push_back(v);
       }
     if(root->left) solve(root->left,ans,v);
     if(root->right) solve(root->right,ans,v);
     v.pop_back();
 }
vector<vector<int>> Paths(Node* root)
{
   vector<vector<int>>ans;
   vector<int>v;
   if(!root) return ans;
   solve(root,ans,v);
   return ans;
}
