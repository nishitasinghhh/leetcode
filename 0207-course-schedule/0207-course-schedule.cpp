class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto it: prerequisites)
        {
            int course=it[0];
            int pre=it[1];
            adj[course].push_back(pre);
        }
        vector<int>indegree(numCourses,0);
        for(int i=0; i<numCourses; i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int>topo;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        if(topo.size()==numCourses) return true;
        return false;
    }
};