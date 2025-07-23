class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};

        int l = 0, r = 0, minLen = 1e9, start = -1;
        int count = 0;
        for(char c: t){
            hash[c]++;
        }

        while(r < s.size()){
            if(hash[s[r]]> 0){
                count++;
            }

            hash[s[r]]--;

            while(count == t.size()){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    start = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) count--;
                l++;
            }
            r++;
        }

        return (start == -1) ? "": s.substr(start, minLen);
    }
};