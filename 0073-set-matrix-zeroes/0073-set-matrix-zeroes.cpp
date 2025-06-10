class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=  matrix.size();
        int m = matrix[0].size();

        set<int> zero_row;
        set<int> zero_col;

        for(int i = 0; i< n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    zero_row.insert(i);
                    zero_col.insert(j);
                }
            }
        }

        for(auto i : zero_row){
            for(int col = 0; col < m; col++){
                matrix[i][col] = 0;
            }
        }

        for(auto i: zero_col){
            for(int row = 0; row < n; row++){
                matrix[row][i] = 0;
            }
        }
    }

};