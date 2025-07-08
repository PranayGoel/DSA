class Solution {
public:
    static bool comp(vector<int> val1, vector<int> val2){
        return val1[1] < val2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);

        int count = 1;
        int lastEndingTime = intervals[0][1];
        for(int i = 1; i< n;i++){
            if(intervals[i][0] >= lastEndingTime){
                count++;
                lastEndingTime = intervals[i][1];
            }
        }
        return n-count;

    }
};