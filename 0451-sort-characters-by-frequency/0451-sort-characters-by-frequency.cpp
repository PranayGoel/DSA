class Solution {
public:
    string frequencySort(string s) {
        
        int n = s.size();
        unordered_map<char, int> mp;

        for(auto c: s){
            mp[c]++;
        }

        vector<vector<char>> buckets(n+1);


        for(auto& [ch, count]: mp){
            buckets[count].push_back(ch);
        }

        string ans;
        for(int i = n; i> 0; i--){
            for(char c: buckets[i])
                ans += string(i, c);
        }

        return ans;

        
    }
};