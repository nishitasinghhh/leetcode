class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq,left,right;
        int maxFreq=INT_MIN;
        for(int i=0; i<n; i++)
        {
            freq[nums[i]]++;
            maxFreq=max(maxFreq,freq[nums[i]]);
            if(left.find(nums[i])==left.end())
                left[nums[i]]=i;
            right[nums[i]]=i;
        }
        int ans=INT_MAX;
        for(auto p:freq)
        {
            if(p.second==maxFreq)
            {
                ans=min(ans,right[p.first]-left[p.first]+1);
            }
        }
        return ans;
    }
};