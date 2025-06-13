class Solution {
public:


    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto num: nums){
            mp[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;

        for(auto it: mp){
            minh.push({it.second, -it.first});
        }
        
        vector<int> ans;

        while(minh.size() > 0){
            for(int i = 0; i< minh.top().first; i++){
                ans.push_back(-minh.top().second);
            }
            minh.pop();
        }


        return ans;


    }
};