class Solution {
public:

    void recurPermute(vector<int> &ds, vector<vector<int>> & ans, vector<int> &nums, int freq[])
    {
        if(ds.size()==nums.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i]=1;
                recurPermute(ds,ans,nums,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>ds;
        int freq[nums.size()];
        for(int i=0; i<nums.size(); i++)
        {
            freq[i]=0;
        }
        recurPermute(ds,ans,nums,freq);
        return ans;
    }
};
//time complexity:- O(N! * N)
//space complexity:- O(N)+O(N)