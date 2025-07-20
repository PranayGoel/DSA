class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;

        string ans = "";
        for(char& c: s){
            if(c == '('){
                if(st.empty()) c = 'x';
                else ans += c;
                st.push(c);

            }
            else{

                st.pop();

                if(st.empty()) c = 'x';
                else ans += c;
            }
        }

        

        return ans;
    }
};