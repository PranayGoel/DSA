class Solution {
public:
    bool f(string s, int ind, int count, vector<vector<int>>& dp){
        int n = s.size();
        if(count < 0) return false;
        if(ind == n) return count == 0? true: false;

        if(dp[ind][count] != -1) return dp[ind][count];

        if(s[ind] == '(') return dp[ind][count]= f(s, ind+1, count+1, dp);
        else if(s[ind] == ')') return dp[ind][count] = f(s, ind+1, count-1, dp);
        else{
            return dp[ind][count]= f(s, ind+1, count+1, dp) || f(s, ind+1, count-1, dp) || f(s, ind+1, count, dp);
        }


    }
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));

        return f(s, 0, 0, dp);
    }
};