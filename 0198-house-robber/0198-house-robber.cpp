class Solution {
public:
    int f(int ind, vector<int>& nums, vector<int>& dp){
        
        if(ind < 0) return 0;
        if(ind == 0) return nums[0];

        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + f(ind-2, nums, dp);
        int not_pick = f(ind-1, nums, dp);

        return dp[ind] = max(pick, not_pick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 0);

        dp[0] = nums[0];

        for(int ind = 1; ind< n ;ind++){
            int pick;
            if(ind == 1) pick = nums[ind];
            else pick = nums[ind] + dp[ind-2];
            int not_pick = dp[ind-1];

            dp[ind] = max(pick, not_pick);
        }

        return dp[n-1];
    }
};