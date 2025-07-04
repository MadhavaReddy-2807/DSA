/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
map<TreeNode*,TreeNode*>mp;
void func(TreeNode*root,TreeNode*parent)
{
    if(root==NULL)
    {
        return;
    }
    mp[root]=parent;
    func(root->left,root);
    func(root->right,root);
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        func(root,NULL);
        queue<TreeNode*>q;
        q.push(target);
        unordered_set<TreeNode*>st;
        st.insert(target);
        while(k--)
        {
            int x=q.size();
            for(int i=0;i<x;i++)
            {
                auto node=q.front();
                q.pop();
                if((node->left)&&(st.find(node->left)==st.end()))
                {
                    cout<<node->left->val;
                    q.push(node->left);
                }
                if(node->right&&(st.find(node->right)==st.end()))
                {
                    q.push(node->right);
                }
                if(mp[node]&&(st.find(mp[node])==st.end()))
                {
                    q.push(mp[node]);
                }
            }
        }
        vector<int>rough;
        while(!q.empty())
        {
           auto node=q.front();
           q.pop();
           rough.push_back(node->val);
        }
        return rough;
    }
};