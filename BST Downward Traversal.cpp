//User function Template for C++
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
public:
long long solve(Node* root ,int x){

       if(root==NULL) return 0;
       long long ans=0;
       if(x==0) ans=root->data;
       ans+=solve(root->left,x-1)+solve(root->right,x+1);
       return ans;
   }

   

    long long solve2(Node *root,int target){

         if(root==NULL) return 0;
        if(root->data==target) return solve(root,0);
        return solve2(root->left,target) + solve2(root->right,target);
    }

   

    long long int verticallyDownBST(Node *root,int target){
       long long ans=solve2(root,target);
       if(ans==0) return -1;
       else return ans-target;
    }
};
