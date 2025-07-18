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
map<TreeNode*,int>mp;
int func(TreeNode*root)
{
    if(root==NULL)
    {
        return 1e5;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        return 0;
    }
   int  left=1+func(root->left);
    int right=1+func(root->right);
   return min(left,right);
}
    int minDepth(TreeNode* root) {
    if(root==NULL)
    {
        return 0;
    }
     return func(root)+1;   
    }
};