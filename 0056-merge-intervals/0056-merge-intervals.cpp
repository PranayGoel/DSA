class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int,int> line;

        for(auto interval: intervals){
            line[interval[0]]++;
            line[interval[1]]--;
        }

        int start;
        vector<vector<int>> ans;
        int count = 0;
        for(auto it: line){
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