class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> line;

        for(auto person: logs){
            line[person[0]]++;
            line[person[1]]--;
        }

        int max_p = 0;
        int ans_year ;
        int count = 0;

        for(auto year: line){
            count += year.second;
            if(count > max_p){
                max_p = count;
                ans_year = year.first;
            }
        }

        return ans_year;
    }
};