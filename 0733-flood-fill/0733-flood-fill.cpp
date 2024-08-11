class Solution {
public:
void dfs(vector<vector<int>>& image, int row, int col, int color,   vector<vector<int>> &vis, int startColor, int drow[], int dcol[])
{  int n=image.size();
        int m=image[0].size();
    vis[row][col]=color;
    for(int i=0; i<4; i++)
    {
        int r=row+drow[i];
        int c=col+dcol[i];
        if(r>=0 && r<n && c>=0 && c<m && image[r][c]==startColor && vis[r][c]!=color)
        {
            dfs(image,r,c,color,vis,startColor,drow,dcol);
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>vis=image;
        int startColor=image[sr][sc];
        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};
        dfs(image,sr,sc,color,vis,startColor,drow,dcol);
        return vis;
    }
};