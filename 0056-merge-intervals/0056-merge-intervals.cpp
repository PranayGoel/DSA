class Solution {
public:
    static bool comp(vector<int>& i1, vector<int>& i2){
        return i1[0] < i2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        vector<vector<int>> merged;

        merged.push_back(intervals[0]);

        for(int i = 1; i< intervals.size(); i++){
            if(merged.back()[1] >= intervals[i][0]){
                merged.back()[1]= max(merged.back()[1], intervals[i][1]);
            }
            else{
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};