

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
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
                if(i==0) ans.push_back(node->data); 
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
