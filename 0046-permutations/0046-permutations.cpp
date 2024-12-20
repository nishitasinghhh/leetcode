class Solution {
public:

    void findPermutations(vector<int>& nums,vector<vector<int>>&ans,vector<int>&ds,int n,int freq[])
    {
        if(ds.size()==n)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<n; i++)
        {
            if(!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i]=1;
                findPermutations(nums,ans,ds,n,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n=nums.size();
        int freq[n];
       for(int i=0; i<n; i++)
       {
           freq[i]=0;
       }
        findPermutations(nums,ans,ds,n,freq);
        return ans;
    }
};
//time complexity:- O(N! * N)
//space complexity:- O(N)+O(N)