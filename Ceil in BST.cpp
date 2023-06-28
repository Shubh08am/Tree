int findCeil(Node* root, int input) {
  
  int ans= INT_MAX;
  
  while(root!=NULL){
      
      if(root->data>=input){
          ans=min(root->data,ans);
          root=root->left;
      }
       else if(root->data<input){
         root=root->right;
      }
  }
 return ans;
   }
