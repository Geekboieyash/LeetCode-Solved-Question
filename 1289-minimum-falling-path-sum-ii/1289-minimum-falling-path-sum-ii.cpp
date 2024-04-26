class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for (int j = 0; j < m; j++) {
            dp[0][j] = grid[0][j];
        }
        
    
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = grid[i][j];
                
                int min_prev = INT_MAX;
                for (int k = 0; k < m; k++) {
                    if (k != j) {
                        min_prev = min(min_prev, dp[i - 1][k]);
                    }
                }
                dp[i][j] += min_prev;
            }
        }
        
        int min_sum = INT_MAX;
        for (int j = 0; j < m; j++) {
            min_sum = min(min_sum, dp[n - 1][j]);
        }
        
        return min_sum;
    }
};