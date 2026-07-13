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
    int findlheight(TreeNode * root)
    {
        if(!root)
        {
            return 0;
        }
        return 1+findlheight(root->left);
    }
    int findrheight(TreeNode * root)
    {
        if(!root)
        {
            return 0;
        }
        return 1+findrheight(root->right);
    }
    int countn(TreeNode*root)
    {
        if(!root)
        {
            return 0;
        }
        int lh=findlheight(root);
        int rh=findrheight(root);
        if(rh==lh)
        {
            return pow(2,lh)-1;
        }
        return 1+countn(root->left)+countn(root->right);
    }
    int countNodes(TreeNode* root) {
        return countn(root);
    }
};