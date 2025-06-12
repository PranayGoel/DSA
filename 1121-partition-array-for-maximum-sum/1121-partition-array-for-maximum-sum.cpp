class Solution {
public:
    int f(int ind, int n, int k, vector<int>& arr, vector<int>& dp){
        if(ind == n) return 0;

        if(dp[ind] != -1) return dp[ind];

        int ans = INT_MIN;
        int maxi = INT_MIN, len = 0;
        for(int i = ind; i < min(ind+k, n); i++){
            len++;
            maxi = max(maxi, arr[i]);
            int sum = (len * maxi) + f(i+1, n, k, arr, dp);
            ans = max(ans, sum);
        }
        return dp[ind]= ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n= arr.size();
        vector<int> dp(n+1, -1);
        return f(0, n, k, arr, dp);
    }
};