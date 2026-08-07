class node{
    public:
    long long  val;
    long long  lazy;
    node*left;
    node*right;
    node(){
        val=0;
        lazy=0;
        left=right=NULL;
    }
};
class st{
    public:
    node *root;
    st()
    {
        root=new node();
    }
    void update(node*root,int nl,int nr,int l,int r)
    {
        if(!root)
        {
            return ;
        }
        if(nl>r||l>nr)
        {
            return;
        }
        if(nl!=nr)
        {
            if(root->left==NULL)
            {
                root->left=new node();
                root->right=new node();
            }
        }
        if(root->lazy)
        {
            root->val=nr-nl+1;
            root->lazy=0;
            if(nl!=nr)
            {
                root->left->lazy=1;
                root->right->lazy=1;
            }
        }
        if(root->val==(nr-nl+1))
        {
            return;
        }
       if(l <= nl && nr <= r)
        {
            root->val=nr-nl+1;
            if(root->left)
            {
                root->left->lazy=1;
                root->right->lazy=1;
            }
            return;
        }
        int mid=(nl+nr)/2;
        if(nl!=nr)
        {
            update(root->left,nl,mid,l,r);
            update(root->right,mid+1,nr,l,r);
            root->val=root->left->val+root->right->val;
        }
    }
};
class CountIntervals {
public:
st *sgt;
    CountIntervals() {
        sgt=new st();      
    }
    
    void add(int left, int right) {
        sgt->update(sgt->root,0,1e9,left,right);
    }
    
    int count() {
        return sgt->root->val;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */