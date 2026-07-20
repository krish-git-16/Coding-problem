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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        if(!root)
        {
            return ans;
        }
        int level=0;
        while(!q.empty())
        {
            int size=q.size();
            level++;
            vector<int>temp(size,0);
            if(level%2)
            {
                for(int i=0;i<size;i++)
                {
                    TreeNode*node=q.front();
                    q.pop();
                    if(node->left)
                    q.push(node->left);
                    if(node->right)
                    q.push(node->right);
                    temp[i]=node->val;
                }
            }    
            else
            {
                for(int i=size-1;i>=0;i--)
                {
                    TreeNode*nod=q.front();
                    q.pop();
                    if(nod->left)
                    q.push(nod->left);
                    if(nod->right)
                    q.push(nod->right);
                    temp[i]=nod->val;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};