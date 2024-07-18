class Solution {
public:
    int findMin(int index, int T,vector<int>& coins,     vector<vector<int>> &dp){
        if(index==0)
        {
            if(T%coins[index]==0)
                return T/coins[index];
            else return 1e9;
        }
        if(dp[index][T]!=-1) return dp[index][T];
        int notTake=0+findMin(index-1,T,coins, dp);
        int take=1e9;
        if(coins[index]<=T)
        {
            take=1+findMin(index,T-coins[index],coins,dp);
        }
        return dp[index][T]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=findMin(n-1,amount,coins,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};