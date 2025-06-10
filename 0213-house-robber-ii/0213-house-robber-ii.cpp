class Solution {
public:

    int f(int start, int end, vector<int>& arr) {
        int n = arr.size();

        int prev1 = arr[start];
        int prev2 = 0;
        int cur;
        for(int i = start+1; i< end; i++){
            if(i == 1) cur = max(arr[i], prev1);
            else{
                int pick = arr[i] + prev2;
                int not_pick = prev1;

                cur = max(pick, not_pick);
            }
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        return max(f(0, n-1, nums), f(1, n, nums));

    }
};