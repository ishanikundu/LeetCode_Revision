top View means we have to print the the first occurence of element in vertical order 
we have to keep track of only vertical and  root node
map dataStructure is used to keep track of vertical and Node as well as in sorted order(which is done automatic) 
eg VerticalOrder :  {-2,A},{1,B},{0,c},{1,D},{2,R}......
queue data structure to store vertical and node 
We have to check wether that vertical order present in map if not present then it is the first vertical push it into map;

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // Your code here
        map<int, int> mp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto current = q.front();
            q.pop();
            Node *node = current.first;
            int vertical = current.second;
            if (mp.find(vertical) == mp.end())
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
