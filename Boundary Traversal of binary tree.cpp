/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
bool isLeaf(Node * root) {
    if(root->left == NULL && root->right == NULL) return true;
    return false;
}

void addleft(Node*root,vector<int>&res){
    Node*curr = root->left;
    
    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addright(Node*root,vector<int>&res){
    Node*curr = root->right;
    vector<int>temp;
    
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for(int i=temp.size()-1;i>=0;--i){
        res.push_back(temp[i]);
    }
}

void addleaves(Node*root,vector<int>&res){
    //pre-order 
    
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
   if(root->left) addleaves(root->left,res);
    if(root->right) addleaves(root->right,res);
}


    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>res;
        if(root==NULL) return res; 
        //add root node else 
        if(!isLeaf(root)) res.push_back(root->data);
        
        addleft(root,res);
        addleaves(root,res);
        addright(root,res);
        
        return res;
        
    }
};
