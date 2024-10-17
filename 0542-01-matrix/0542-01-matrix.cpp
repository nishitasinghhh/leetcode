class Solution {
public:
    void bfs(vector<vector<int>>& mat,vector<vector<int>>& vis,vector<vector<int>>& dist)
    {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int row=it.first.first;
            int col=it.first.second;
            int step=it.second;
            dist[row][col]=step;
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int i=0; i<4; i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] )
                {
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},step+1});
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        bfs(mat,vis,dist);
        return dist;
    }
};