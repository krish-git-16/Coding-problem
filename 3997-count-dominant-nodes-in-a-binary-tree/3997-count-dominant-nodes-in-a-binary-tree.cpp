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
    int solve(TreeNode* root,int &ans)
    {
        if(!root)
        {
            return 0;
        }
        if(!root->left&&!root->right)
        {
            ans++;
            return root->val;
        }
        int m=max(solve(root->left,ans),solve(root->right,ans));
        if(root->val>=m)
        {
            ans++;
            return root->val;
        }
        return m;
    }
    int countDominantNodes(TreeNode* root) {
        int ans=0;
        int a=solve(root,ans);
        return ans;
    }
};