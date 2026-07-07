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
    int burn(TreeNode* root, int start, int &timer)
    {
        if(!root)
        {
            return 0;
        }
        if(root->val==start)
        {
            return -1;
        }
        int left=burn(root->left,start,timer);
        int right=burn(root->right,start,timer);
        if(left<0)
        {
            timer=max(timer,abs(left)+right);
            return left-1;
        }
        if(right<0)
        {
            timer=max(timer,abs(right)+left);
            return right-1;
        }
        return 1+max(left,right);
    }
    void find(TreeNode* root,TreeNode* &BurnNode,int start)
    {
        if(!root)
        {
            return ;
        }
        if(root->val==start)
        {
            BurnNode=root;
            return ;
        }
        find(root->left,BurnNode,start);
        find(root->right,BurnNode,start);
    }
    int height(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    int amountOfTime(TreeNode* root, int start) {
        int timer=0;
        int t=burn(root,start,timer);
        TreeNode* BurnNode=NULL;
        find(root,BurnNode,start);
        int h=height(BurnNode)-1;
        return max(h,timer);
    }
};