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
    int solve(TreeNode* root,int sum,int &ans)
    {
        if(!root)
        {
            return 0;
        }
        int left=solve(root->left,sum,ans);
        int right=solve(root->right,sum,ans);
        ans=max(ans,root->val+left+right);
        sum=root->val+max(left,right);
        if(sum<0)
        {
            return 0;
        }
        return sum;
    }
    int maxPathSum(TreeNode* root) {
        int sum=0;
        int ans=INT_MIN;
        if(!root->left&&!root->right)
        {
            return root->val;
        }
        int a=solve(root,sum,ans);
        return ans;
    }
};