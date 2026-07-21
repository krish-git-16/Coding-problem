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
    void get(TreeNode* root,int &mi,int &ma,int i)
    {
        if(!root)
        {
            return ;
        }
        mi=min(i,mi);
        ma=max(i,ma);
        get(root->left,mi,ma,i-1);
        get(root->right,mi,ma,i+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        if(!root)
        {
            return {};
        }
        q.push({root,0});
        int mi=INT_MAX,ma=INT_MIN;
        get(root,mi,ma,0);
        vector<vector<int>>ans(ma-mi+1);
        while(!q.empty())
        {
            int size=q.size();
            vector<pair<int,int>> temp;
            for(int i=0;i<size;i++)
            {
                TreeNode*node=q.front().first;
                int index=q.front().second;
                q.pop();
                temp.push_back({index,node->val});
                if(node->left)
                q.push({node->left,index-1});
                if(node->right)
                q.push({node->right,index+1});
            }
            sort(temp.begin(),temp.end());

            for(auto &it:temp)
            {
                ans[it.first-mi].push_back(it.second);
            }
        }
        return ans;
    }
};