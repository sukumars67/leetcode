class Solution {
public:
    bool f(int i,int target,vector<int>&nums,vector<vector<int>>& dp)
    {
        if(target==0)return true;
        if(i==0)
        {
            return target==nums[0];
        }
        if(dp[i][target]!=-1) return dp[i][target]==1?true:false;
        bool pick=false;
        bool notpick=f(i-1,target,nums,dp);
        if(target>=nums[i])
        {
         pick=f(i-1,target-nums[i],nums,dp);
        }
        dp[i][target]=pick || notpick?1:0;
        return pick || notpick;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum %2==1)
        return false;
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        return f(n-1,sum/2,nums,dp);

        
    }
};