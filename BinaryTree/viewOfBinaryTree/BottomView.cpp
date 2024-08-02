
Traverse all node into the map and update the map everytime and it will get updated and the last node will be printed 
class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        // Your Code Here
        map<int, int> mp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto current = q.front();
            q.pop();
            Node *node = current.first;
            int vertical = current.second;
            mp[vertical] = node->data;
            if (node->left != NULL)
                q.push({node->left, vertical - 1});
            if (node->right != NULL)
                q.push({node->right, vertical + 1});
        }
        vector<int> ans;
        for (auto i : mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};