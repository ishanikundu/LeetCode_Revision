// Between two Nodes you have to find longest path 

class Solution{
public:
int maximumDiameter = INT_MIN;
int diameter(TreeNode* root){
    if(root == NULL) return 0;
    int leftHeight = diameter(root->left);
    int rightHeight = diameter(root->right);
    maximumDiameter = max(maximumDiameter,leftHeight+rightHeight);
    return 1 + max(rightHeight,leftHeight);
}
int maxDiameter(TreeNode* root){
    diameter(root);
    return maximumDiameter;
 }
};