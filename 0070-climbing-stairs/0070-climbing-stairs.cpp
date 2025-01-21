class Solution {
public:
int climbStairs(int n)
    {
         if(n==1 || n==2)
         {
            return n;
         }
        int c=0;
        int p1=1;
        int p2=2;
        for(int i=3;i<=n;i++)
        {
           c=p1+p2;
           p1=p2;
           p2=c;
        }
        return c;
    }
   
};