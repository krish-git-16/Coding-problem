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
    int height(TreeNode*root)
    {
        if(!root)
        return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        int h=height(root);
        q.push(root);
        int level=0;
        while(!q.empty())
        {
            int size=q.size();
            level++;
            if(level==h)
            break;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
        }
        return q.front()->val;
    }
};