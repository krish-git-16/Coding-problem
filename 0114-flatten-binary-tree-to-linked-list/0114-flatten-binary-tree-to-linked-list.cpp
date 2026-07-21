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
    void solve(TreeNode* root)
    {
        if(!root)
        {
            return ;
        }
        TreeNode*parent=root;
        if(root->left)
        {
            TreeNode*lchild=root->left;
            root=root->left;
            while(root->right)
            {
                root=root->right;
            }
            root->right=parent->right;
            parent->right=lchild;
            parent->left=NULL;
            solve(lchild);
        }
        solve(root->right);
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};