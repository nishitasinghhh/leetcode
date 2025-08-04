class Solution {
public:
void bfs(int n, int m, int sr,int sc, int color, int startColor, vector<vector<int>>& image,vector<vector<int>> &finalImage)
{
    finalImage[sr][sc]=color;
    queue<pair<int,int>>q;
    q.push({sr,sc});
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        int row=it.first;
        int col=it.second;
        for(int i=0; i<4; i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==startColor && finalImage[nrow][ncol]!=color)
            {
                q.push({nrow,ncol});
                finalImage[nrow][ncol]=color;
            }
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>finalImage=image;
        int startColor=image[sr][sc];
        bfs(n,m,sr,sc,color,startColor,image,finalImage);
        return finalImage;
    }
};