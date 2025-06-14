class Solution {
public:
    int solve(int e, int f, vector<vector<int>>& dp){
        if(f == 0 || f == 1) return f;
        if( e == 1 ) return f;

        if(dp[e][f] != -1) return dp[e][f];

        int total_moves = INT_MAX;
        for(int k = 1; k < f; k++){
            int moves = 1 + max( solve(e-1, k-1,dp) , solve(e, f-k, dp) );
            total_moves = min(total_moves, moves);
        }

        return dp[e][f] = total_moves;
    }
    int superEggDrop(int k, int n) {
        //vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        //return solve(k, n, dp);

        vector<vector<int>> dp(k+1, vector<int>(n+1, 0));

        for(int e = 1; e<= k; e++){
            dp[e][1] = 1;
        }
        for(int f = 1; f <=n; f++){
            dp[1][f] = f;
        }

        for(int e = 2; e <= k; e++){
            for(int f = 2; f <= n; f++){
                int total_moves = 1e8;

                /*
                for( int floor = 1; floor <= f; floor++){
                    int moves = 1 + max( dp[e-1][floor-1], dp[e][f-floor]);
                    total_moves = min(total_moves, moves);
                }
                */

                int low = 1;
                int high = f;
                while(low <= high){
                    int mid = low + (high-low)/2;
                    int break_case = dp[e-1][mid-1];
                    int survive_case = dp[e][f-mid];

                    int worst_case = 1 + max(break_case, survive_case);

                    total_moves= min(total_moves, worst_case);

                    if(break_case > survive_case)
                        high = mid-1;
                    else
                        low = mid+1;
                }
                dp[e][f] = total_moves;
            }
        }

        return dp[k][n];

    }
};