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
class Solution {
  public:
    void parentMarker(Node* root, int target, map<Node*,Node*>&mp,Node*&tar){
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node*node = q.front() ; q.pop() ; 
            if(node->data==target) tar=node;
            if(node->left){
                mp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right]=node;
                q.push(node->right);
            }
        }
    }
    int minTime(Node* root, int target) {
        map<Node*,Node*>mp;
        map<Node*,int>visited;
        Node*tar=NULL;
        parentMarker(root,target,mp,tar);
        int time=0;
        queue<Node*>q;
        q.push(tar);
        visited[tar]=1;
        
        while(!q.empty()){
            int sz = q.size() ;
            int burn=0;
            while(sz--){
                Node*node = q.front()  ; q.pop() ; 
            
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=1;
                    burn=1;
                }
                
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=1;
                    burn=1;
                }
                
                if(mp[node] && !visited[mp[node]]){
                    q.push(mp[node]);
                    visited[mp[node]]=1;
                    burn=1;
                }
             }
            time+=burn>0?1:0;
        }
        return time;
    }
};
