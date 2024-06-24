class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int maxCount=INT_MIN;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i]==1)
            {
                cnt++;
            }
            maxCount=max(maxCount,cnt);
            if(nums[i]==0)
            {
                cnt=0;
            }
        }
        return maxCount;
    }
};