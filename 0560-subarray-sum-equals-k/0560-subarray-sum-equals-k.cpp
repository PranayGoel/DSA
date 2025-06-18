class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        // prefix_sum , count

        mp[0] = 1;
        int prefixSum = 0;
        int count = 0;
        for(int i = 0; i< nums.size() ;i++){
            prefixSum += nums[i];
            count += mp[prefixSum-k];
            mp[prefixSum]++;


        }   
        return count;


    }
};