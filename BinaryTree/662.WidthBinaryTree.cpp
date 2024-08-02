class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        typedef unsigned long long ll;
           ll maximum = 0;
        // if i try to go at the end of the level and try to count the number of nodes ?
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            ll first = q.front().second;
            ll last = q.back().second;
            while(size){
              auto current = q.front();
              q.pop();
              TreeNode* node=current.first;
              ll indx = current.second;
              if(node->left != NULL) q.push({node->left,2*indx+1});
              if(node->right != NULL) q.push({node->right,2*indx+2});
               size--;
            }
            //  check the width 
            maximum = max(maximum, last-first +1);
        }
        return maximum;
    }
};