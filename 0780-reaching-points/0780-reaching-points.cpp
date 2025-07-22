class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(sx>tx||sy>ty)
        {
            return false;
        }
        if(sx==tx&&sy==ty)
        {
            return true;
        }
        while(sx<tx&&sy<ty)
        {
            if(tx>ty)
            {
                tx=tx-ty;
            }
            else
            {
                ty=ty-tx;
            }
        }
         if(sx==tx&&sy==ty)
        {
            return true;
        }
        if(sx>tx||sy>ty)
        {
            return false;
        }
        if(sx==tx)
        {
            if((ty-sy)%tx==0)
            {
                return true;
            }
            return false;
        }
        if(sy==ty)
        {
            if((tx-sx)%ty==0)
            {
                return true;
            }
            return false;
        }
       return false;
    }
};