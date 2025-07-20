class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int n= s.size();

        char c = s[0];

        vector<int> match_indices;
        for(int i =0; i< n; i++ ){
            if(c == goal[i]){
                match_indices.push_back(i);
            }
        }
        if(match_indices.empty()) return false;

        for(auto index: match_indices ){
            index = (index+1)%n;
            int match = 1;
            int i = 1;
            while(i < n){
                if(s[i] == goal[index]){
                    i++;
                    index = (index+1)%n;
                    match++;
                }
                else break;
            }
            if(match == n) return true; 
        }

        return false;


    }
};