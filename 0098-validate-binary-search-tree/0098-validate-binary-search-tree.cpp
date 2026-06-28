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
    void solve(vector<int>&arr,TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        solve(arr,root->left);
        arr.push_back(root->val);
        solve(arr,root->right);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>arr;
        solve(arr,root);
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]<=arr[i-1])
            {
                return 0;
            }
        }
        return 1;
    }
};