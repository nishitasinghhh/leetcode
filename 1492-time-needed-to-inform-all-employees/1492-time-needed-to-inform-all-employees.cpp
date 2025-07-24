class Solution {
public:
int ans=INT_MIN;
void bfs( unordered_map<int,vector<int>> &adj, vector<int>& informTime, int headID)
{
    queue<pair<int,int>>q;
    q.push({headID,0});
    while(!q.empty())
    {
        int cur_emp=q.front().first;
        int cur_time=q.front().second;
        q.pop();
        ans=max(ans,cur_time);
        for(auto ngbr:adj[cur_emp])
        {
            q.push({ngbr,cur_time+informTime[cur_emp]});
        }
    }
}
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>>adj;
        for(int i=0; i<manager.size(); i++)
        {
            int manager_i=manager[i];
            if(manager_i!=-1)
            {
                adj[manager_i].push_back(i);
            }
        }
        bfs(adj,informTime,headID);
        return ans;
    }
};