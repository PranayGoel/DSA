class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        vector<vector<int>> ans;
        map<int,int> mp;

        for(int i = 0; i< n; i++){
            mp[intervals[i][0]]++;
            mp[intervals[i][1]]--;
        }

        mp[newInterval[0]]++;
        mp[newInterval[1]]--;


        int count = 0;
        int start;
        for(auto it: mp){
            if(count == 0){
                start = it.first;
            }
            count += it.second;

            if(count == 0){
                ans.push_back({start, it.first});
            }
        }

        return ans;
        
    }
};