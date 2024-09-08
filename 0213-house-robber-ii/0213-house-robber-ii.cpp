class Solution {
public:
    int findSum(vector<int> &arr)
    {
        int n=arr.size();
        int prev=arr[0];
        int prev2=0;
        for(int i=1; i<n; i++)
        {
            int pick=arr[i];
            if(i>1) pick+=prev2;
            int not_pick=0+prev;
            int curi=max(pick,not_pick);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int>temp1;
        vector<int>temp2;
       
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0; i<n; i++)
        {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(findSum(temp1),findSum(temp2));
    }
};