class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==0)
         {
            return 0;
         }
         int result;
         result=right;
         while(left<right)
          {
            right=right&right-1;
            if(result==0)
             {
                return 0;
             }
          }
          return right;
    }
};