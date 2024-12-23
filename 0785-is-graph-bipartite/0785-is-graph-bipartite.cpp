class Solution {
public:
bool dfs(int node,int col,int color[], vector<int>adj[])
{
    color[node]=col;
    for(auto it:adj[node])
    {
        if(color[it]==-1)
        {
            if(dfs(it,!col,color,adj)==false) return false;
        }
        else if(color[it]==col)
        {
            return false;
        }
    }
    return true;

}
    bool isBipartite(vector<vector<int>>& graph) {

        int V=graph.size();
        vector<int>adj[V];
        for(int i=0; i<V; i++)
        {
            for(auto x:graph[i])
            {
                adj[i].push_back(x);
            }
        }
        int color[V];
        for(int i=0; i<V; i++) color[i]=-1;
        for(int i=0; i<V; i++)
        {
            if(color[i]==-1)
            {
                if(dfs(i,0,color,adj)==false) return false;
            }
        }
        return true;
    }
};