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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        int count = 0;
        while (!q.empty())
        {
            int size = q.size();
            count++;
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode *root = q.front();
                q.pop();
                level.push_back(root->val);
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
            if (count % 2 == 0)
                reverse(level.begin(), level.end());
            ans.push_back(level);
        }
        return ans;
    }
};