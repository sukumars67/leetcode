class Solution {
public:
    void set0(vector<vector<int>> &matrix,int i,int j,int n,int m)
    {
        for(int a=i;a>=0;a--)
        {
            matrix[a][j]=0;
        }
        for(int a=i;a<n;a++)
        {
            matrix[a][j]=0;
        }
        for(int b=j;b<m;b++)
        {
            matrix[i][b]=0;
        }
        for(int b=j;b>=0;b--)
        {
           matrix[i][b]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n,m;
        n=matrix.size();
        m=matrix[0].size();
        vector<vector<int>> matrix1(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                matrix1[i][j]=matrix[i][j];
            }
        }
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    set0(matrix1,i,j,n,m);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                matrix[i][j]=matrix1[i][j];
            }
        }
        
    }
};