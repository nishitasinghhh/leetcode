class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n=grid.size();
        int m=grid[0].size();
        int startRow=0;
        int startCol=0;
        int endRow=n-1;
        int endCol=m-1;
       int drow[]={-1,-1,0,1,1,1,0,-1};
        int dcol[]={0,1,1,1,0,-1,-1,-1};
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[startRow][startCol]=1;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int dist=it.first;
            int row=it.second.first;
            int col=it.second.second;
            for(int i=0; i<8; i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && dist+1<dis[nrow][ncol])
                {
                    dis[nrow][ncol]=1+dist;
                    q.push({1+dist,{nrow,ncol}});
                }
            }
        }
        if(dis[endRow][endCol]==1e9)
        return -1;
        return dis[endRow][endCol];
    }
};