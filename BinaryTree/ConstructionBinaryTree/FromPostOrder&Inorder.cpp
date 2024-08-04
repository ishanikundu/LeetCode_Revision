Tricks : 1)PostOrder we know  left Right Root so we can say last element will give us root
         2) we have to keep track of PostIndex that will be initialized from postorder.size()-1
         3) everytime we have do postIndex --;
         4) initialize TreeNode* root = new TreeNode(postOrder[postIndex]) ;
         4) search for inorder[i] == root->val then store ith value to  inorderIndex
         5) function must carry (inorder,postorder PostIndex, start, end)
         first traverse for root->right  start = 0,end = inIndex-1;
         then root->left start = inIndex+1, end = size()-1;
         6) return root;

         Link = https : // leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
        
        
        
        class Solution
         {
         public:
             TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
             {
                 int postIndex = postorder.size() - 1;
                 TreeNode *root = constructTree(inorder, postorder, postIndex, 0, inorder.size() - 1);
                 return root;
             }
             TreeNode *constructTree(vector<int> &inorder, vector<int> &postorder, int &postIndex, int &start, int &end)
             {
                 if (start > end)
                     return NULL;
                 int inIndex = 0;
                 TreeNode *root = new TreeNode(postorder[postIndex]);
                 for (int i = start; i <= end; i++)
                 {
                     if (inorder[i] == root->val)
                     {
                         inIndex = i;
                         break;
                     }
                 }
                 postIndex--;
                 root->left = constructTree(inorder, postorder, postIndex, start, inIndex - 1);
                 root->right = constructTree(inorder, postorder, postIndex, inIndex + 1, end);
                 return root;
             }
         };