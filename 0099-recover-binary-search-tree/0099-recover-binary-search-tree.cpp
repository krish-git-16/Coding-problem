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
    void solve(TreeNode*root,TreeNode*&first,TreeNode*&middle,TreeNode*&last,TreeNode*&prev)
    {
        if(!root)
        return ;
        solve(root->left,first,middle,last,prev);
        if(prev&&prev->val>root->val)
        {
            if(!first)
            {
                first=prev;
                middle=root;
            }
            else
            {
                last=root;
            }
            
        }
        prev=root;
        solve(root->right,first,middle,last,prev);
    }
    void recoverTree(TreeNode* root) {
        TreeNode*first=NULL,*middle=NULL,*last=NULL,*prev=NULL;
        solve(root,first,middle,last,prev);
        if(!last)
        swap(first->val,middle->val);
        else
        swap(first->val,last->val);
    }
};