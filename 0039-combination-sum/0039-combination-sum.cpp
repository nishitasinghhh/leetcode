class Solution {
public:
void findCombinations(int index, vector<int>& candidates,int target,vector<vector<int>> &ds,vector<int> &ans,int n )
{
    if(index==n)
    {
        if(target==0)
        {
            ds.push_back(ans);
        }
        
            return;
    }
    if(candidates[index]<=target)
    {
        ans.push_back(candidates[index]);
        findCombinations(index,candidates, target-candidates[index],ds,ans,n);
        ans.pop_back();
    }
     findCombinations(index+1,candidates, target,ds,ans,n);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ds;
        vector<int>ans;
        int n=candidates.size();
        findCombinations(0,candidates,target,ds,ans,n);
        return ds;
    }
};