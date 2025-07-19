class Solution {
public:
    
    unordered_map<int, bool> memo;

    bool canPartition(vector<int>&nums,int mask, int currSum, int k,int& t) {
        int n = nums.size();
        if (k == 0) return mask == 0; // all elements used

        if (currSum == t) {
            // Found one full subset → move to next
            return canPartition(nums,mask, 0, k - 1,t);
        }

        if (memo.count(mask)) return memo[mask];

        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) { // if nums[i] not used
                if (currSum + nums[i] > t) continue;

                // mark nums[i] as used
                if (canPartition(nums,mask ^ (1 << i), currSum + nums[i], k,t)) {
                    return memo[mask] = true;
                }
            }
        }

        return memo[mask] = false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;

        int target = sum / k;
    

        int fullMask = (1 << n) - 1;
        return canPartition(nums,fullMask, 0, k,target);
    }
};