class Solution {
public:
void bfs(int n, int m, vector<vector<int>> &visited,vector<vector<int>>& grid, int &time)
{
    queue<pair<pair<int,int>,int>>q;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j]==2)
            {
                q.push({{i,j},0});
                visited[i][j]=1;
            }
            
        }
    }
    
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        int row=it.first.first;
        int col=it.first.second;
        int tm=it.second;
        time=max(time,tm);
        for(int i=0; i<4; i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !visited[nrow][ncol])
            {
                q.push({{nrow,ncol},tm+1});
                visited[nrow][ncol]=1;
            }
        }
    }

}
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int time=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        bfs(n,m,visited,grid,time);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                {
                    return -1;
                }
            }
        }
        return time;
    }
};