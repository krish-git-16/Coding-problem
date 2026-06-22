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
class Solution {
public:
    TreeNode*create(vector<int>& preorder,int &index,int bound)
    {
        if(index==preorder.size()||preorder[index] > bound)
        {
            return NULL;
        }
        TreeNode*temp=new TreeNode(preorder[index++]);
        temp->left=create(preorder,index,temp->val);
        temp->right=create(preorder,index,bound);
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return create(preorder,index,INT_MAX);
    }
};