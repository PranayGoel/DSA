class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps(n+1);

        gaps[0] = startTime[0];
        gaps[n] = eventTime - endTime[n-1];

        for(int i = 1; i< n ;i++){
            gaps[i] = startTime[i] - endTime[i-1];
        }

        int l = 0;
        int r = k;
        int sum = 0;
        int maxSum;

        for(int i = l ; i <= r && i <= n; i++){
            sum += gaps[i];
        }
        maxSum = sum;

        while(r < n){
            sum -= gaps[l++];
            sum += gaps[++r];
            maxSum = max(sum, maxSum);
        }

        return maxSum;



    }
};