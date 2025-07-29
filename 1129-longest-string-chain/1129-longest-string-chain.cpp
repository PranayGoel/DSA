class Solution {
public:
    bool isPossible(string a, string b) {
        int n = b.size();
        if(a.size() + 1 != b.size()) return false;

        int i = 0, j  = 0;
        bool skipped = false;

        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else{
                if(skipped) return false;
                skipped = true;
                j++;
            }
        }
        return true;
    }
    
    static bool comp(string a, string b){
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        sort(words.begin(), words.end(), comp);
        for(int i = 1; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(isPossible(words[prev], words[i]) && dp[prev] + 1 > dp[i]){
                    dp[i] = dp[prev] + 1;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
            }
        }

        return maxi;
    }
};
