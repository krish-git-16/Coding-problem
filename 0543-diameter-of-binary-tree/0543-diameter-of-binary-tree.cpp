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
    int d(TreeNode* root,int &ans)
    {
        if(!root)
        {
            return 0;
        }
        int left=d(root->left,ans);
        int right=d(root->right,ans);
        int temp=1+left+right;
        ans=max(ans,temp);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        int a=d(root,ans);
        return ans-1;
    }
};