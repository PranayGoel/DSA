class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;

        for(auto num : nums){
            mp[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minh;

        for(auto it: mp){
            minh.push({it.second, it.first});
            if(minh.size() > k){
                minh.pop();
            }
        }

        vector<int> ans;
        while(minh.size() > 0){
            ans.push_back(minh.top().second);
            minh.pop();
        }

        return ans;
    }
};