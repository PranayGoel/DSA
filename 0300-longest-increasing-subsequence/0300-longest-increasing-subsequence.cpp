class Solution {
public:

    

    int f(int ind, int prev_ind, vector<int>& nums, int n, vector<vector<int>>& dp){
        if(ind == n) return 0;
        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];

        int len = f(ind+1, prev_ind, nums, n, dp); // not_take
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            len = max(len,1+ f(ind+1, ind, nums, n, dp));
        }

        return dp[ind][prev_ind+1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {    
        int n = nums.size();

        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i = 1; i< n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;


        
    }
};