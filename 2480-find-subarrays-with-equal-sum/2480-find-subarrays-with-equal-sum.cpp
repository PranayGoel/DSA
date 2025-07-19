class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> map;
        for(int i = 1, n = nums.size(); i < n; ++i){
            if(!map.insert(nums[i - 1] + nums[i]).second) return true;
        }
        return false;
    }
};