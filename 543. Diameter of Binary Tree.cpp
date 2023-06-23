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
    //APPROACH-1 O(N*N) 
    int solve(TreeNode*root,int&diameter){
        if(!root) return 0;
        int lh = solve(root->left,diameter) ;
        int rh = solve(root->right,diameter) ;
        diameter=max(diameter,lh+rh);
        solve(root->left,diameter);
        solve(root->right,diameter);
        return 1+max(lh,rh);
    }
    //APPROACH-2 O(N)
    int solve2(TreeNode*root,int&dia){
        if(!root) return 0;
        int lh=solve2(root->left,dia);
        int rh=solve2(root->right,dia);
        dia=max(dia,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
      //  int diameter = 0;
      //  solve(root,diameter);
     //   return diameter; APPROACH-1

          int dia = 0;
         solve2(root,dia);
         return dia; //APPROACH-2
    }
};
