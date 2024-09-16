class Solution {
public:
   int findCoins(int index, int target, vector<int>& coins,vector<vector<int>> &dp)
   {
       if(index==0)
       {
           return (target%coins[index]==0);
       }
       if(dp[index][target]!=-1) return dp[index][target];
       int not_take=findCoins(index-1, target,coins,dp);
       int take=0;
       if(coins[index]<=target)
       {
           take=findCoins(index,target-coins[index],coins,dp);
       }
       return dp[index][target]=take+not_take;
   }
    int change(int amount, vector<int>& coins) {
       int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return findCoins(n-1,amount,coins,dp);
    }
};