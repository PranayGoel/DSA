class Solution {
public:
    bool isOdd(int num){
        
        return num%2;
    }

    int solve(vector<int>& nums, int k){
        if(k < 0) return 0;
        int n = nums.size();
        int l = 0, r = 0, oddCount = 0, count = 0;

        while(r < n){
            if(isOdd(nums[r])) {
                oddCount++;
            }

            while(oddCount > k){
                if(isOdd(nums[l])) oddCount--;
                l++;
            }

            count += (r-l+1);
            r++;
        }

        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};