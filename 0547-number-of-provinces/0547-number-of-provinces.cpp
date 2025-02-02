class Solution {
public:
    void print(vector<vector<int>>& is,int n,int sv,vector<int> &vis)
    {
        vis[sv]=1;
        for(int i=0;i<n;i++)
        {   if(i==sv)
        {
            continue;
        }
            if(is[sv][i]==1)
            {  if(vis[i])
            {continue;}
                print(is,n,i,vis);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& is) {
        int n=is.size();
       vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                count++;
                print(is,n,i,vis);

            }
        }
        return count;
        
    }
};