class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        int n=nums.size();
        for(int i=0; i<n; i++) //to store positive and negative
        {
            if(nums[i]<0)
            {
                neg.push_back(nums[i]);
            }
            else
            {
                pos.push_back(nums[i]);
            }
        }
        for(int i=0; i<n/2; i++)
        {
            nums[2*i]=pos[i]; // postive at even index
            nums[2*i+1]=neg[i]; //negative at odd index
        }
        return nums;
    }
};
//time complexity:- O(N)+O(n/2)
//space complexity:- O(n)