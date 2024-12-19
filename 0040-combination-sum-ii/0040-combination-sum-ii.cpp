class Solution {
public:
void findCombinations(int ind, int target,vector<int>& candidates,vector<vector<int>>&ans, 
                        vector<int>&ds, int n)
{
    if(target==0)
    {
        ans.push_back(ds);
        return;
    }
    for(int i=ind; i<n; i++)
    {
        if(i>ind && candidates[i]==candidates[i-1]) continue;
        if(candidates[i]>target) break;
        ds.push_back(candidates[i]);
        findCombinations(i+1,target-candidates[i],candidates,ans,ds,n);
        ds.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        int n=candidates.size();
        findCombinations(0,target,candidates,ans,ds,n);
        return ans;
    }
};