class node{
    public:
    node*links[26];
    int prefix;
    int isend;
    node()
    {
        for(int i=0;i<26;i++)
        {
            links[i]=NULL;
        }
        prefix=0;
        isend=0;
    }
    bool contains(char c)
    {
        return links[c-'a']!=NULL;
    }
    void create(char c)
    {
        links[c-'a']=new node();
    }
};
class trie
{
    public:
    node*root;
    trie()
    {
        root=new node();
    }
    void insert(string s)
    {
        node*temp=root;
        for(int i=0;i<s.length();i++)
        {
            if(!temp->contains(s[i]))
            {
               temp->create(s[i]);
            }
            temp=temp->links[s[i]-'a'];
            temp->prefix++;
        }
        temp->isend=true;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        trie *t=new trie();
        for(int i=0;i<strs.size();i++)
        {
            t->insert(strs[i]);
        }
        sort(strs.begin(),strs.end(),[](string &a,string &b){
            return a.length()<b.length();
        });
        int x=strs[0].length();
        node*root=t->root;
        string s=strs[0];
        int n=strs.size();
        int index=-1;
        for(int i=0;i<x;i++)
        {
            root=root->links[s[i]-'a'];
            if(root->prefix!=n)
            {
                index=i;
                break;
            }
        }
        if(index!=-1)
        {
            return s.substr(0,index);
        }
        return "";
    }
};