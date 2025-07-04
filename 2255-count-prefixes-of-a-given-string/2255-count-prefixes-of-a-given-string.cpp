class Solution {
public:
class node{
    public:
    node*links[26];
    node()
    {
        for(int i=0;i<=25;i++)
        {
            links[i]=NULL;
        }
    }
    bool contains(char ch)
    {
        return this->links[ch-'a']!=NULL;
    }
    void create(char ch)
    {
       this->links[ch-'a']=new node();
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
        node*rough=root;
        for(int i=0;i<s.length();i++)
        {
            if(!rough->contains(s[i]))
            {
                rough->create(s[i]);
            }
            rough=rough->links[s[i]-'a'];
        }
    }
}; 
bool check(node*root,string s)
{
    node*temp=root;
   for(int i=0;i<s.length();i++)
   {
      if(!temp->contains(s[i]))
      {
        return false;
      }
      temp=temp->links[s[i]-'a'];
   }
   return true;
}
    int countPrefixes(vector<string>& words, string s) {
        trie*tr=new trie();
        tr->insert(s);
        int count=0;
        for(auto it:words)
        {
            if(it.length()<=s.length())
            {
                count+=check(tr->root,it);
            }
        }
        return count;
    }
};