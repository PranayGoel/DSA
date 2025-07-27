class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        

        int sum = 0, maxSum = INT_MIN;

        for(auto num: nums){
            
            if(sum < 0) sum = 0;
            sum += num;
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};