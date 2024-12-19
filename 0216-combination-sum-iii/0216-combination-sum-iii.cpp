class Solution {
public:
void solve(int k,int n,vector<int>temp, vector<vector<int>>&ans,int ind)
{
    if(n==0 && k==0)
    {
        ans.push_back(temp);
        return;
    }
    for(int i=ind; i<=9; i++)
    {
        if(k==0) break;
        temp.push_back(i);
        solve(k-1,n-i,temp,ans,i+1);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(k,n,temp,ans,1);
        return ans;

    }
};