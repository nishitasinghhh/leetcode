class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double prefix=0;
        double suffix=0;
        double ans=nums[0];
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;
             prefix=prefix*nums[i];
            suffix=suffix*nums[n-i-1];
            ans=max(ans,max(prefix,suffix));
        }
        return ans;
    }
};