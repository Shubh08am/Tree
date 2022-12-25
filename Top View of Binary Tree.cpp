/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root){
        
        vector<int>ans;
       if(root==NULL) {
      return ans;
  }
        
        // q stores node and line
 queue<pair<Node*,int>>q;
 //map stores nodes value along with line 
  map<int,int>mp;
  
  //initially, queue contains root and line=0
  q.push({root,0});
 while(!q.empty()){
        auto it = q.front() ; //take front of queue 
        //pop it than 
        q.pop();
        //assign to node 
        Node*node = it.first ; 
        //line value 
        int line = it.second;
        
        //see in map if that line doesn't exist assign nodes value to it 
        if(mp.find(line)==mp.end()){
           mp[line] = node->data; //store in map
        }
        
        //see for left sub-tree 
        if(node->left != NULL) {
            //assign that node in queue alongwith decrease in level
            q.push({node->left,line-1});
        }
        //see for right sub-tree 
        if(node->right != NULL) {
            //assign that node in queue alongwith increase in level
            q.push({node->right,line+1});
        }
        
    }    
    
    //map stores ans in sorted order of line i.e left to right
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
    }

};
