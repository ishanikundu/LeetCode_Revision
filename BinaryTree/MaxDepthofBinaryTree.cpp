// same as levelOrder Traversal



class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        int count = 0;
        queue<TreeNode *> q;
        if (root == NULL)
            return 0;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            while (size)
            {
                TreeNode *cur = q.front();
                if (cur->left != NULL)
                    q.push(cur->left);
                if (cur->right != NULL)
                    q.push(cur->right);
                q.pop();
                size--;
            }
            count++;
        }
        return count;
    }
};

--------------------------------------------

Sol 2 :
// Link to Diameter of Binary tree
int maxDepth(TreeNode* root){
    if(root==NULL) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth,rightDepth);
}