class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto edge: edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int N=edges.size();
        int n=adj.size();
        int center;
        for(int i=1; i<=n; i++)
        {
            if(adj[i].size()==N)
            {
                center=i;
            }
        }
        return center;
    }
};