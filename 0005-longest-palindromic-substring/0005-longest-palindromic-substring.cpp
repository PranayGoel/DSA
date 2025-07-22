class Solution {
public:
    string longestPalindrome(string s) {
        
        string ans = "";
        int len = 0;

        int n = s.size();
        for(int i = 0; i<n; i++ ){
            
            int l = i, r = i;

            while(l >= 0 && l < n && r < n && r >= 0 && s[l] == s[r]){
                if(r-l+1 > len){
                    ans = s.substr(l, r-l+1);
                    len = r -l + 1;
                }
                l--;
                r++;
            }

            l = i, r = i+1;

            while(l >= 0 && l < n && r < n && r >= 0 && s[l] == s[r]){
                if(r-l+1 > len) {
                    ans = s.substr(l, r-l+1);
                    len = r-l+1;
                }
                l--;
                r++;
            }

        }

        return ans;
    }
};