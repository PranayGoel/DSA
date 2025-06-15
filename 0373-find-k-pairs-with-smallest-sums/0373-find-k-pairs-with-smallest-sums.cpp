
/*
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, vector<int>>> maxh;

        for(int i = 0; i< nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                maxh.push(make_pair(nums1[i] + nums2[j] , vector<int>{nums1[i], nums2[j]}));
                if(maxh.size() > k) maxh.pop();
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
*/
typedef tuple<int,int,int> tu;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tu, vector<tu>, greater<tu>> minh;
        set<pair<int,int>> visited;

        vector<vector<int>> ans;
        if(nums1.empty() || nums2.empty() || k == 0) return ans;
        minh.push({nums1[0] + nums2[0], 0, 0});
        visited.insert({0, 0});

        while(k > 0 and !minh.empty()){
            auto [sum, i, j] = minh.top();
            minh.pop();
            ans.push_back({nums1[i], nums2[j]});

            if(j + 1 < nums2.size() && !visited.count({i, j+1})){
                minh.push({nums1[i] + nums2[j+1], i, j+1});
                visited.insert({i, j+1});
            }

            if(i + 1 < nums1.size() && !visited.count({i+1, j})){
                minh.push({nums1[i+1]+ nums2[j], i+1, j});
                visited.insert({i+1, j});
            }

            k--;
        }

        return ans;


    }
};

