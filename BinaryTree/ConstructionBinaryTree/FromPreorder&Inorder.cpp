Tricks : 1)PreOrder we know   Root left Right so we can say first element will give us root
         2) we have to keep track of PreIndex that will be initialized from 0
         3) everytime we have do preIndex ++;
         4) initialize TreeNode* root = new TreeNode(preOrder[preIndex]) ;
         4) search for inorder[i] == root->val then store ith value to  inorderIndex
         5) function must carry (inorder,preorder,preIndex, start, end)
         first traverse for root->left  start = 0,end = inIndex-1;
         then root->right start = inIndex + 1, end = size() - 1;
         6) return root;

         Link : https :leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
        
        
         class Solution
         {
         public:
             TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
             {
                 int preIndex = 0;
                 TreeNode *root = constructTree(preorder, inorder, preIndex, 0, inorder.size() - 1);
                 return root;
             }
             TreeNode *constructTree(vector<int> &preorder, vector<int> &inorder, int &preIndex, int start, int end)
             {
                 if (start > end)
                     return NULL;

                 int inIndex;
                 TreeNode *root = new TreeNode(preorder[preIndex]);
                 preIndex++;
                 for (int i = start; i <= end; i++)
                 {
                     if (inorder[i] == root->val)
                     {
                         inIndex = i;
                         break;
                     }
                 }
                 root->left = constructTree(preorder, inorder, preIndex, start, inIndex - 1);
                 root->right = constructTree(preorder, inorder, preIndex, inIndex + 1, end);

                 return root;
             }
         };