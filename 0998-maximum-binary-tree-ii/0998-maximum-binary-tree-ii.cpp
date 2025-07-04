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
vector<int>rough;
void preorder(TreeNode*root)
{
    if(root==NULL)
    {
        return;
    }
    preorder(root->left);
    rough.push_back(root->val);
    preorder(root->right);
}
int maxiindex(vector<int>rough,int l,int r)
{
    int maxi=INT_MIN;
    int result;
    for(int i=l;i<=r;i++)
    {
        if(rough[i]>maxi)
        {
            result=i;
            maxi=rough[i];
        }
    }
    return result;
}
TreeNode*create(vector<int>&rough,int l,int r)
{
    if(l>r)
    {
        return NULL;
    }
    int index=maxiindex(rough,l,r);
    TreeNode* root=new TreeNode(rough[index]);
    root->left=create(rough,l,index-1);
    root->right=create(rough,index+1,r);
    return root;

}
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        preorder(root);
        rough.push_back(val);
        return create(rough,0,rough.size()-1);
    }
};