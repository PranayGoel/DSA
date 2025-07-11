class Solution {
public:
    int upperBound(int endTime, vector<vector<int>>& jobs){
        int low = 0;
        int high = jobs.size() - 1;
        int ans = jobs.size();

        while(low <= high){
            int mid = low +(high-low)/2;

            if(jobs[mid][0] >= endTime){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    int f(int ind,  vector<vector<int>>& jobs, vector<int>& dp){
        int n = jobs.size();
        if(ind == n) return 0;

        int start = jobs[ind][0];
        int end = jobs[ind][1];
        int profit = jobs[ind][2];

        if(dp[ind] != -1) return dp[ind];

        int not_pick = f(ind +1, jobs, dp);
        int next = upperBound(end, jobs);
        int pick = profit + f(next, jobs, dp);


        return dp[ind] = max(pick, not_pick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for(int i = 0; i< n ;i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n, -1);

        return f(0, jobs, dp);
    }
};