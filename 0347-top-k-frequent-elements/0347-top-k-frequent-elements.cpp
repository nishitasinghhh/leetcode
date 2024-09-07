class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>mpp;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            mpp[nums[i]]++;
        }
priority_queue<pair<int,int>>pq;
        for(auto it:mpp)
        {
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        while(k-- && !pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};