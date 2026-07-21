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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int &i,int l ,int r)
    {
        if(l>r)
        {
            return NULL;
        }
        TreeNode* temp=new TreeNode(postorder[i]);
        int mid;
        for(int j=l;j<r;j++)
        {
            if(postorder[i]==inorder[j])
            {
                mid=j;
                break;
            }
        }
        i--;
        temp->right=solve(inorder,postorder,i,mid+1,r);
        temp->left=solve(inorder,postorder,i,l,mid-1);
        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int i=n-1;
        return solve(inorder,postorder,i,0,n-1);
    }
};