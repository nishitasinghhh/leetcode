class Solution {
public:
void dfs(int row, int col,vector<vector<int>> &vis,vector<vector<int>>& grid)
{
    vis[row][col]=1;
    int n=grid.size();
        int m=grid[0].size();
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    for(int i=0; i<4; i++)
    {
        int nrow=row+drow[i];
        int ncol=col+dcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
        {
            dfs(nrow,ncol,vis,grid);
        }
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0; i<m; i++)
        {
            if(grid[0][i]==1 && !vis[0][i])
            {
                dfs(0,i,vis,grid);
            }
            if(grid[n-1][i]==1 && !vis[n-1][i])
            {
                dfs(n-1,i,vis,grid);
            }
        }
        for(int j=0; j<n; j++)
        {
            if(grid[j][0]==1 && !vis[j][0])
            {
                dfs(j,0,vis,grid);
            }
            if(grid[j][m-1]==1 && !vis[j][m-1])
            {
                dfs(j,m-1,vis,grid);
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

