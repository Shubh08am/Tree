/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
  // Iterative Approach using level order traversal
        vector<int>ans;
        queue<Node*>q;//stores nodes

        if(root==NULL){
            return ans; //i.e empty
        }
        //else insert root  in queue
        q.push(root);

        while(!q.empty()){
            vector<int>level;
            int size_to_traverse = q.size();//traversing till size of each level
               
            for(int i=0;i<size_to_traverse;i++){
                //see if left and right exist if yes insert that nodes in queue
              Node*node = q.front();
                q.pop();//remove from queue
                if(i==size_to_traverse-1) ans.push_back(node->data); 
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                } 
            }
    }
    return ans;
    }
};
