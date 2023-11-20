class Solution {
public:
    int solve(vector<vector<int>>& matrix,int i,int j, vector<vector<int>>& dp)
    {
        if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size() || matrix[i][j]==0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=1+min(solve(matrix,i-1,j-1, dp),min(solve(matrix,i-1,j, dp),solve(matrix,i,j-1, dp)));
    }
    
    
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int count=0;
       // memset(t,-1,sizeof(t));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==1)
                    count+=solve(matrix,i,j,dp);
            }
        }
        return count;
    }
};