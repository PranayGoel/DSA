class Solution {
public:
    bool compare(string s1, string s2){
        int n = s1.size();
        int m = s2.size();
        if(n != m+1) return false;

        int i = 0;
        int j = 0;

        while( i < n){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        if(i == n && j == m) return true;
        else return false;
        
    }

    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);
        int maxi =1;
        for(int i = 1; i< n; i++){
            for(int j = 0; j < i; j++){
                if(compare(words[i], words[j]) && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
            if(dp[i]> maxi) maxi = dp[i];
        }
        return maxi;

    }
};