/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        vector<int> ans;
        if (root == NULL)
            return ans;
        TreeNode *current;
        while (!q.empty())
        {
            int size = q.size();
            while (size)
            {
                current = q.front();
                if (current->left != NULL)
                    q.push(current->left);
                if (current->right != NULL)
                    q.push(current->right);
                size--;
                q.pop();
            }
            ans.push_back(current->val);
        }
        return ans;
    }
};