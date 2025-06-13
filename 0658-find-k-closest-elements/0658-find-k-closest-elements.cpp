class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;

        priority_queue<pair<int,int>> maxh;

        for(auto num : arr){
            maxh.push(make_pair(abs(num-x), num));
            if(maxh.size() > k){
                maxh.pop();
            }
        }
        while(maxh.size() > 0){
            ans.push_back(maxh.top().second) ;
            maxh.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};