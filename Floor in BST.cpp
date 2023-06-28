int floor(Node* root, int x) {
     int ans = -1;
    while(root!=NULL){
        
        if(root->data<=x){
            ans=max(ans,root->data);
            root=root->right;
        }
        else if(root->data>x) {
            root=root->left;
        }
    }
    return ans;
}
