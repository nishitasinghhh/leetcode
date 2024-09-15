class Solution {
public:
    bool f(int index, vector<int> &nums, int target,vector<vector<int>> &dp)
    {
        if(target==0) return true;
        if(index==0) return nums[index]==target;
        if(dp[index][target]!=-1) return dp[index][target];
        bool not_take=f(index-1,nums,target,dp);
        bool take=false;
        if(nums[index]<=target)
            take=f(index-1,nums,target-nums[index],dp);
        return dp[index][target]=not_take||take;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        int s=sum/2;
        vector<vector<int>>dp(n,vector<int>(s+1,-1));
        return f(n-1,nums,s,dp);
    }
};