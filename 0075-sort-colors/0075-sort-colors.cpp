class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int count0=0;
        int count1=0;
        int count2=0;
        for(int i=0; i<n; i++) // used to store the number of 0's 1'sand 2's int the 
                               // given array
        {
            if(nums[i]==0)
            {
                count0++;
            }
            else if(nums[i]==1)
            {
                count1++;
            }
            else
            {
                count2++;
            }
        }
        for(int i=0; i<count0; i++) // updating 0;
        {
            nums[i]=0;
        }
        for(int i=count0; i<count0+count1; i++) // updating 1;
        {
            nums[i]=1;
        }
        for(int i=count0+count1; i<n; i++) // updating 2;
        {
            nums[i]=2;
        }
    }
};
// time complexity:- O(2N)
// space complexity:-o(1)