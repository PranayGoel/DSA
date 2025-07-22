class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;

        int n = s.size();
        int count = 0;

        int maxCount = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(s[i]);
                count++;
                maxCount = max(maxCount, count);
            }
            else if(s[i] == ')'){
                st.pop();
                count--;
            }
        }

        return maxCount;
    }
};