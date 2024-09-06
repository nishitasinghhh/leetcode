class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long>pq;
        int n=gifts.size();
        for(int i=0; i<n; i++)
        {
            pq.push(gifts[i]);
        }
        while(k)
        {
            int max_gift=pq.top();
            pq.pop();
            pq.push(floor(sqrt(max_gift)));
            k--;
        }
        long long sum=0;
        while(!pq.empty())
        {
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};