class Solution
{
public:
    vector<int> ans;
    vector<int> postorder(Node *root)
    {
        postTraversal(root, ans);
        return ans;
    }
    void postTraversal(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        for (Node *i : root->children)
        {
            postTraversal(i, ans);
        }
        ans.push_back(root->val);
    }
};