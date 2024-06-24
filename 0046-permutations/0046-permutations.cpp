class Solution {
public:
void findPermute(vector<vector<int>>&ans, vector<int>ds, vector<int>nums,int n,int freq[])
{
    if(ds.size()==nums.size()) // base case where the size of permutation becomes equal to the number of element
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
                findPermute(ans,ds,nums,n,freq);
            freq[i]=0;
            ds.pop_back();
            }
            
        }
}
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans; // store all the permutations
        vector<int>ds; //single permutation
        
        int n=nums.size();
        int freq[n]; // map
            for(int i=0; i<n; i++)
            {
                freq[i]=0;
            }
        findPermute(ans,ds,nums,n,freq);
        return ans;
    }
};
//time complexity:- O(N! * N)
//space complexity:- O(N)+O(N)