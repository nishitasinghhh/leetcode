class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        if(grid[0][0]==1)return -1;
        int start_row=0;
        int start_col=0;
        int trow=grid.size()-1;
        int tcol=grid[0].size()-1;
        
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>>q;
        dist[start_row][start_col]=1;
        q.push({1,{0,0}});
         int drow[]={-1,-1,0,1,1,1,0,-1};
        int dcol[]={0,1,1,1,0,-1,-1,-1};
        while(!q.empty())
        {
            int dis=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            for(int i=0; i<8; i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && dist[nrow][ncol]>dis+1)
                {
                    dist[nrow][ncol]=dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }
         if(dist[trow][tcol]==1e9)//path not possible
            return -1;
        return dist[trow][tcol];
    }
};