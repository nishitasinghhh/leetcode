class Solution {
public:
void powerSet(int i,vector<vector<int>> &ds,vector<int>ans,vector<int>& nums,int n)
{
    if(i>=n)
    {
    ds.push_back(ans);
    return;
    }
    
    ans.push_back(nums[i]);
    powerSet(i+1,ds,ans,nums,n);
    ans.pop_back();
    powerSet(i+1,ds,ans,nums,n);
}

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>ds;
        int n=nums.size();
        vector<int>ans;
        powerSet(0,ds,ans,nums,n);
        return ds;
    }
};