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
    void solve(vector<vector<int>> &ans,TreeNode* root, int targetSum, int sum,vector<int>temp)
    {
        temp.push_back(root->val);
        if(!root->left&&!root->right)
        {
            if(sum + root->val == targetSum)
            ans.push_back(temp);
            return ;
        }
        if(root->left)
        solve(ans,root->left,targetSum,sum+root->val,temp);
        if(root->right)
        solve(ans,root->right,targetSum,sum+root->val,temp);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
        {
            return {};
        }
        vector<int>temp;
        vector<vector<int>>ans;
        solve(ans,root,targetSum,0,temp);
        return ans;
    }
};