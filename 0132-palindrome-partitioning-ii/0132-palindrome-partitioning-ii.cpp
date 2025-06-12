class Solution {
public:
    bool isPalindrome(string s){

        for(int i= 0; i< s.size()/2;i++){
            if(s[i] != s[s.size()-i-1]) return false;
        }
        return true;
    }
    int f(int i, int n, string &s, vector<int>& dp){
        if(i== n) return 0;

        if(dp[i] != -1) return dp[i];

        string temp = "";
        int mini = 1e8;
        for(int j = i ; j < n; j++){
            temp += s[j];
            if(isPalindrome(temp)){
                int cost = 1 + f(j+1, n, s, dp);
                mini = min(cost,  mini);
            }    
        }
        return dp[i]= mini;
    }

    int minCut(string s) {
        int n = s.size();
        //vector<int>dp(n, -1);
        //return f(0, n, s,dp)-1;

        vector<int> dp(n+1,0);
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(s[i]==s[j] && (j-i<2 || palindrome[i+1][j-1])){
                    palindrome[i][j] = true;
                }
            }
        }
        for(int i = n-1; i>= 0; i--){
            string temp = "";
            int mini = 1e8;
            for(int j = i; j< n; j++){
                temp += s[j];
                if(palindrome[i][j]){
                    int cost = 1 + dp[j+1];
                    mini = min(cost, mini);
                }
            }
            dp[i] = mini;
        
        }
        return dp[0]-1;    
    }

};