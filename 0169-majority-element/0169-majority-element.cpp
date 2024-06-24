class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            mpp[nums[i]]++;
        }
        int t=n/2;
        for(auto it:mpp)
        {
            if(it.second >t)
            {
                return it.first;
            }
        }
        return -1;
    }
};
//time complexity:- O(NlogN)+O(N)
//space complexity:-O(N)
