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
 set<int>leaf;
vector<TreeNode*>roots;
map<int,TreeNode*>mp;
bool isbst(TreeNode* root, long long &prev) {
        if (!root) return true;
        if (!isbst(root->left, prev)) return false;
        if (root->val <= prev) return false;
        prev = root->val;
        return isbst(root->right, prev);
    }

 void inorder(TreeNode*root)
 {
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        leaf.insert(root->val);
    }
    inorder(root->left);
    inorder(root->right);
 }
 TreeNode*merge(TreeNode*root)
 {
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        if(mp[root->val]!=NULL)
        {
            TreeNode*res=mp[root->val];
            mp[root->val]=NULL;
            res->left=merge(res->left);
            res->right=merge(res->right);
            return res;
        }
    }
    root->left=merge(root->left);
    root->right=merge(root->right);
    return root;
 }
class Solution {
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
    leaf.clear();
    roots.clear();
    mp.clear();
        if(trees.size()==1)
        {
            return trees[0];
        }
        for(auto tree:trees)
        {
            mp[tree->val]=tree;
            roots.push_back(tree);
            inorder(tree);
        }
        TreeNode*finalroot=NULL;
        for(auto root:roots)
        {
            if(leaf.find(root->val)==leaf.end())
            {
                finalroot=root;
                break;
            }
        }
        int n=trees.size();
            finalroot=merge(finalroot);
    
            long long prev=LLONG_MIN;
            if(!isbst(finalroot,prev))
            {
                return NULL;
            }
        int count=0;
        for(auto it:mp)
        {
            if(it.second!=NULL)
            {
                count++;
            }
        }
        if(count>=2)
        {
            return NULL;
        }
        return finalroot;
    }
};