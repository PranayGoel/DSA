class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxLen = INT_MIN, maxf = 0;
        int n = s.size();

        unordered_map<char, int> mp;
        while(r < n){
            mp[s[r]]++;

            maxf = max(maxf, mp[s[r]]);

            if(r-l+1 - maxf > k){
                mp[s[l]]--;
                maxf = 0;
                for(auto it: mp){
                    if(it.second > maxf) maxf = it.second;
                }
                l++;
            }

            maxLen = max(maxLen, r-l+1);
            r++;

        }

        return maxLen;
    }
};