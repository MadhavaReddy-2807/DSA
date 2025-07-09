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
vector<TreeNode*>result;
map<string,int>mp;
string func(TreeNode*root,string rough)
{
    if(root==NULL)
    {
        return "#";
    }
    string left=func(root->left,rough);
    string right=func(root->right,rough);
    string temp=to_string(root->val)+left+right;
    if(mp.find(temp)!=mp.end())
    {
        result.push_back(root);
    }
    else
    {
        mp[temp]=1;
    }
    return temp;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string x=func(root,"");
        vector<TreeNode*>res;
        map<int,TreeNode*>mp1;
        for(int i=0;i<result.size();i++)
        {
            mp1[result[i]->val]=result[i];
        }
        for(auto it:mp1)
        {
            res.push_back(it.second);
        }
        return res;
    }
};