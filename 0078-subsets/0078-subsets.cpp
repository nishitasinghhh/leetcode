class Solution {
public:

void powerSet(int index,vector<vector<int>> &ds,vector<int>&ans,vector<int>& nums,int n)
{
    if(index>=n)
    {
        ds.push_back(ans);
        return;
    }
    ans.push_back(nums[index]);
    powerSet(index+1, ds, ans, nums, n);
    ans.pop_back();
    powerSet(index+1, ds,ans,nums,n);
}
    vector<vector<int>> subsets(vector<int>& nums) 
    {
       vector<vector<int>>ds;
        vector<int>ans;
        int n=nums.size();
        powerSet(0,ds,ans,nums,n);
            return ds;
    }
};