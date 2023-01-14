

/*struct Node
{
	int data;
	Node *left, *right;
};*/

Node*constructBST(int& pointAt , int* postorder , int lowerBound){ 
       if( pointAt<0 || lowerBound > postorder[pointAt]) {
           return NULL;
       }
        Node* root = new Node( postorder[pointAt] );
       pointAt--;
       
        root->right = constructBST(pointAt,postorder,root->data);
        root->left = constructBST(pointAt,postorder,lowerBound);
       
       return root;
   }

 
Node *constructTree (int post[], int size)
{
 int pointAt=size-1;  
return  constructBST(pointAt,post,INT_MIN);
}
