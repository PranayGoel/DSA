class Solution {
public:

    int f_1(int ind, int prev, int len, vector<int>& nums, int n){
        if(ind >= n) return len;

        if(nums[ind] > prev){
            return max(f_1(ind+1, nums[ind], len+1, nums, n) , f_1(ind+1, prev, len, nums, n));
        }
        else{
            return max(f_1(ind+1, prev, len, nums, n) , f_1(ind+1, nums[ind], 1,nums, n) );
        }
    }

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

        vector<vector<int>>dp(nums.size(), vector<int>(nums.size()+1, -1));
        return f(0, -1, nums, nums.size(), dp);
        
    }
};