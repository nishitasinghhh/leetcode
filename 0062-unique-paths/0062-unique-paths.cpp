class Solution {
private:
    
   

public:
    int countPath(int i, int j, int n, int m,vector<vector<int>> &dp)
    {
        if(i==(n-1) && j==(m-1)) return 1;
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
       else return dp[i][j]= countPath(i+1,j,n,m,dp)+countPath(i,j+1,n,m,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
       return countPath(0,0,m,n,dp);
    }
};