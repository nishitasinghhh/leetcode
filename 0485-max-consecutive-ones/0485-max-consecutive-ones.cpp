class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int cnt=0;
        int max_ones=INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==1)
                cnt++;
            max_ones=max(max_ones,cnt);
            if(nums[i]==0)
                cnt=0;
            
        }
        return max_ones;
    }
};