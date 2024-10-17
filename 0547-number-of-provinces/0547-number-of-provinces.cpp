class Solution {
public:


    

void dfs(int node, vector<int>adj[], vector<int> &vis)
{
    vis[node]=1;
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it,adj,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
       int v=isConnected.size();
        vector<int>adj[v];
        for(int i=0; i<v; i++)
        {
            for(int j=0; j<v; j++)
            {
                if(isConnected[i][j]==1  && i!=j)
                {
                    adj[i].push_back(j);
                adj[j].push_back(i);
                }
                
            }
        }
        int num_of_province=0;
        vector<int>vis(v,0);
        for(int i=0; i<v; i++)
        {
            if(!vis[i])
            {
                num_of_province++;
                dfs(i,adj,vis);
            }
        }
        return num_of_province;
    }
};