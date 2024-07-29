
vector<vector<int>LevelOrderTraversal(TreeNode* root){
    
    queue<TreeNode*>q;
    
    vector<vector<int>result;
    if (root == NULL)
        return result;

    q.push(root);
    Not write-- > q.push(root->val);

    while (!q.empty())
    {
        int size = q.size();
        vector<int>temp;
        while(size){
            TreeNode* cur = q.front();
            temp.push_back(cur);
            if(cur->left!= NULL)    q.push(cur->left);         NOT WRITE  -->  q.push(cur->left->val); as it typecasting is done as TreeNode
            if(cur->right != NULL) q.push(cur->right);
            q.pop();
            size--;
        }
        result.push_back(temp);
      }
         return result;
    }

