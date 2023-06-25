//User function template for C++

/*
struct Node 
{
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
  void solve(Node* root,long long currSum, long long targetSum,map<long long,long long>&mp,int&cnt){
        if(!root)return;
        
        currSum+=root->data;
        cnt+=mp[currSum-targetSum];
        mp[currSum]++;
        if(root->left)solve(root->left,currSum,targetSum,mp,cnt);
        if(root->right)solve(root->right,currSum,targetSum,mp,cnt);
        mp[currSum]--;
    }
    int sumK(Node *root,int k)
    {
        int cnt=0;
        if(!root) return 0;
        map<long long,long long>mp;
        mp[0]=1;
        solve(root,0,k,mp,cnt);
        return cnt;
    }
};
