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
    void solve(TreeNode* root,int sum,int &ans)
    {
        if(!root)
        {
            return ;
        }
        if(!root->left&&!root->right)
        {
            ans+=sum;
            return;
        }
        if(root->left)
        solve(root->left,sum*10+root->left->val,ans);
        if(root->right)
        solve(root->right,sum*10+root->right->val,ans);
    }
    int sumNumbers(TreeNode* root) {
        int sum=root->val,ans=0;
        solve(root,sum,ans);
        return ans;
    }
};