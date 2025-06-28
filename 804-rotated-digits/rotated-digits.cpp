class Solution {
public:
int func(int index,int tight,string s,int valid)
{
    if(index==s.size())
    {
        return valid==1;
    }
    int limit=tight?s[index]-'0':9;
    int count=0;
    for(int i=0;i<=limit;i++)
    {
        if(i==4||i==7||i==3)
        {
            continue;
        }
        int new_tight=tight&&(i==limit);
        int new_valid=valid||i==2||i==5||i==6||i==9;
        count+=func(index+1,new_tight,s,new_valid);
        
    }
    return count;
}
    int rotatedDigits(int n) {
        string x=to_string(n);
        return func(0,1,x,0);
    }
};