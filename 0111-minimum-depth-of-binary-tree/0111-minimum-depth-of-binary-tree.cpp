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
    int solve(TreeNode* root)
    {
        if(!root->left && !root->right)
        {
            return 1;
        }
        int l,r;
        if(root->right)
        r=solve(root->right);
        
        if(root->left)
        l=solve(root->left);
        
        if(!root->left&&root->right)
        {
            return 1+r;
        }

        if(root->left&&!root->right)
        { 
            return 1+l;
        }    
        return 1+min(l,r);
    }
    int minDepth(TreeNode* root) {
        if(!root)
        return 0;
        return solve(root);
    }
};