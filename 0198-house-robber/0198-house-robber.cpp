class Solution {
public:
    int f(int i,vector<int> &nums,vector<int> &dp)
    {
        if(i==0)return nums[0];
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int first=nums[i]+f(i-2,nums,dp);
        int notpick=0+f(i-1,nums,dp);
        dp[i]=max(first,notpick);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(n-1,nums,dp);
    }
};