class Solution {
public:

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> sumFreq;
        sumFreq[0] = 1;
        int sum = 0;
        int count = 0;
        for(auto num: nums){
            sum += num;

            if(sumFreq.count(sum - goal)){
                count += sumFreq[sum-goal]; 
            }

            sumFreq[sum]++;
        }
        return count;
    }
};