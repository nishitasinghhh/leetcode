class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int index=-1; // first breaking point
        for(int i=n-2; i>=0; i--) //to find the breaking point
        {
            if(nums[i]<nums[i+1])
            {
                index=i;
                break;
            }
        }
        if(index==-1)  // do not have a break point
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1; i>index; i--)  //finding the first smallest element greater than the break point
        {
            if(nums[i]>nums[index])
            {
                swap(nums[i],nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1, nums.end());
        return ;
        
    }
};
// time complexity:-O(N)+O(N)+O(N);
//space complexity:-O(N)