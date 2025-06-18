class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size()/3;
        set<int> ans;
        unordered_map<int,int>mp;

        for(auto num: nums){
            mp[num]++;
            if(mp[num] > n) ans.insert(num); 
        }

        return vector<int>(ans.begin(), ans.end());
    }
};