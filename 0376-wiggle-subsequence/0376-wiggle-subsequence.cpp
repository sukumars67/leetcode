// Same as leetcode 1027, 376, 3202

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>>dp(2, vector<int>(n+1, 1)); // row(top to bottom) r0 for positive difference, r1 for negative difference

        int maxLen = 1;

        for(int i=0; i<n; i++){

            for(int j=0; j<i; j++){

                int diff = nums[i]-nums[j];

                if(diff >0){

                    dp[0][i] = max(dp[0][i], 1 + dp[1][j]);
                    maxLen = max(maxLen, dp[0][i]);
                }

                else if (diff < 0){

                    dp[1][i] = max(dp[1][i], 1 + dp[0][j]);
                    maxLen = max(maxLen, dp[1][i]);
                }
            }

        }

        return maxLen;
    }
};