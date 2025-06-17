/*
class Solution {
public:
    
    int solve(int ind, int k, vector<int>& nums, vector<vector<int>>& dp){
        if(k == 1){
            int sum  =0;
            for(int i = ind; i< nums.size(); i++){
                sum += nums[i];
            }
            return sum;
        }

        if(dp[ind][k] != -1) return dp[ind][k];

        int leftSum = 0;
        int ans = INT_MAX;
        for(int i = ind; i <= nums.size() -k; i++){
            leftSum += nums[i];
            int rightSum = solve(i+1, k-1, nums, dp);
            int temp = max(leftSum, rightSum);
            ans = min(ans, temp);
        }
        return dp[ind][k] = ans;
    }
    
    
    int splitArray(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(k+1, -1));
        return solve(0, k, nums, dp);    
    
    }
};

*/

class Solution {
public:
    int numberOfSplits(vector<int>& nums, int maxSum){

        int splits = 1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] <= maxSum) sum += nums[i];
            else{
                sum = nums[i];
                splits++;
            }
        }

        return splits;
    }
    int splitArray(vector<int>& nums, int k){
        int n = nums.size();
        if(k > n) return -1;
        int max = INT_MIN;
        int sum = 0;

        for(auto num: nums){
            sum += num;
            if(num > max) max = num;
        }
        
        int high = sum;
        int low = max;
        int ans;
        while(low <= high){
            int mid = low + (high-low)/2;
            int splits = numberOfSplits(nums, mid);
            if(splits > k) low = mid+1;
            else{
                ans = mid;
                high = mid-1;
            }
        }

        return ans;


    }
};
