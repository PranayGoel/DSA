class Solution {
public:
    int distance(int x1, int x2) {
        return x1 * x1 + x2 * x2;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,vector<int>>> maxh;

        for(auto it: points){
            maxh.push(make_pair(distance(it[0],it[1]), it));
            if(maxh.size() > k){
                maxh.pop();
            }
        }

        vector<vector<int>> ans;

        while(maxh.size() > 0){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }

        return ans;
    }
};