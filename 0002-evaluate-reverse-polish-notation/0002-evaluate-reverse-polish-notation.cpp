class Solution {
public:
    stack<int>s;
    bool  check(string oper)
    {
        if(oper=="+"||oper=="-"||oper=="/"||oper=="*")
         {
            return true;
         }
         return false;
    }
    int value(int a,int b,string oper)
     {
        if(oper=="+")
         {
            return a+b;
         }
         else if(oper=="-")
          {
            return a-b;
          }
          else if(oper=="*")
          {
            return a*b;
          }
          else
          {
            return a/b;
          }
     }
    int evalRPN(vector<string>& tokens) {
        int a,b;
        for(int i=0;i<tokens.size();i++)
         {
             if(check(tokens[i]))
              {
                b=s.top();
                s.pop();
                a=s.top();
                s.pop();
                s.push(value(a,b,tokens[i]));
              }
              else
              {
                s.push(stoi(tokens[i]));
              }

         }
        return s.top();
    }
};