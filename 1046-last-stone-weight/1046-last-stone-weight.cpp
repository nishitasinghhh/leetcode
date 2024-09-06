class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int>pq;
        for(int i=0; i<n; i++)
        {
            pq.push(stones[i]);
        }
        while(pq.size()>1)
        {
            int weight=pq.top();
            pq.pop();
            weight-=pq.top();
            pq.pop();
            pq.push(weight);
        }
        return pq.empty()?0:pq.top();
    }
};