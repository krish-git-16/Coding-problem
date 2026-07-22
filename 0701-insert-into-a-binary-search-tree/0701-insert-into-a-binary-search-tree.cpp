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
    void solve(TreeNode* root,int val)
    {
        if(!root->left&&!root->right)
        {
            if(val<root->val)
            root->left=new TreeNode(val);
            else
            root->right=new TreeNode(val);
        }
        else if(!root->left&&val<root->val)
        {
            root->left=new TreeNode(val);
        }
        else if(!root->right&&val>root->val)
        {
            root->right=new TreeNode(val);
        }
        else if(val<root->val)
        solve(root->left,val);
        else
        solve(root->right,val);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(!root)
        {
            TreeNode*root=new TreeNode(val);
            return root;
        }    
        solve(root,val);
        return root;
    }
};