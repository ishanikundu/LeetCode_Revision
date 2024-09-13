WE Know that Inorder of binarySearch Tree are arrange in ascending order
So from there we will first generate the array ans which in ascending order
and then check whether first element smaller than next element if not 
return false


vector<int>ans;
    bool isValidBST(TreeNode* root) {
    inorder(root,ans);
    for(int i = 1; i < ans.size(); i++){
        if(ans[i] <= ans[i-1]){
            return false;
        }
    }
    return true;
    }
    void inorder(TreeNode* root, vector<int>& ans){
        if(root == NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }