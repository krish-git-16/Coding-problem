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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &i,int l,int r)
    {
        if(l>r)
        {
            return NULL;
        }
        int mid=i;
        TreeNode* root=new TreeNode(preorder[i]);
        int flag=0;
        for(int j=l;j<=r;j++)
        {
            if(preorder[i]==inorder[j])
            {
                mid=j;
                flag=1;
                break;
            }
        }
        i++;
        root->left=solve(preorder,inorder,i,l,mid-1);
        root->right=solve(preorder,inorder,i,mid+1,r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size(),m=inorder.size();
        TreeNode* root=NULL;
        int i=0;
        root=solve(preorder,inorder,i,0,m-1);
        return root;
    }
};