
// Moris Traversal using 0(1) space not using extra space
// we use the concept of threaded binary tree

-----------------------------------------------------------------------------------------
It works on 3 cond we have to check those conditions
cnd1:: if cur->left exists  
       > check right Exists     
 cnd2::    if Yes 
                  got to the rightMost of the leftChild untill it reaching to null 
                      an assign it to cur [thread being  connected to current]
 cnd3::           if No 
                   leftChild will get Assign to cur 
    if cur->left doesn t  exists 
        > ans.push_back cur->val
          cur = cur->right

-------------------------------------------------------------------------------------




class Solution
{
public:
    vector<int> inOrderTraversal(TreeNode *root)
    {
        TreeNode* cur = root;
        vector<int>ans;
        while(cur!= NULL){
            TreeNode* leftChild = cur->left;
            if(leftChild != NULL){ 
              // left Exists
             while(leftChild->right!=NULL){
                    // left's -> right exists
                    leftChild = leftChild->right;
                 }
                 leftChild->right = cur;
                 TreeNode* temp = cur;
                 cur = cur ->left;
                 temp->left = NULL;
            }
            else{
                // Doesn't exists
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ans;
    }
};