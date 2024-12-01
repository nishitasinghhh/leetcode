class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        vector<int>ParityArray(n);
        int even=0;
        int odd=1;
        for(int i=0; i<n; i++)
        {
            if(nums[i]%2==0)
            {
                ParityArray[even]=nums[i];
                even=even+2;
            }
            else
            {
                ParityArray[odd]=nums[i];
                odd=odd+2;
            }
        }
        return ParityArray;
    }
};