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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        if(!root)
        {
            return ans;
        }
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size-1;i++)
            {
                TreeNode* n=q.front();
                q.pop();
                if(n->left)
                q.push(n->left);
                if(n->right)
                q.push(n->right);
            }
            ans.push_back(q.front()->val);
            if(q.front()->left)
            q.push(q.front()->left);
            if(q.front()->right)
            q.push(q.front()->right);
            q.pop();
        }
        return ans;
    }
};