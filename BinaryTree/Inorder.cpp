vector<int>inOrderTraversal(TreeNode* root){
     vector<int>ans;
     inOrder(root,ans);
     return ans;
}
void inOrder(TreeNode* root, int ans){
//    just return. Dont have to return any value , comeback to the position from where it was called
    if(root==NULL) return;
    inOrder(root->left,ans);
    ans.push_back(root->val);
    inOrder(root->right,ans);
}



// -----------------------

why we cannot write in same main function ??

vector<int>inOrderTraversal(TreeNode root){
    if(root== NULL) return ans;
    inOrderTraversal(root->left);
    ans.push_back(root->val);
    inOrderTraversal(root->right);
}

// as ans will not be accumulated in one single ans it will break into multiple ans vector so this approach will be wrong