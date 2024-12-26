class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       int n=nums.size();
        int low=0;
        int same=0;
        int high=n;
        for(auto it:nums)
        {
            if(it<pivot)
            {
                same++;
            }
            else if(it>pivot)
            {
                high--;
            }
        }
        vector<int>res(n);
        for(auto it:nums)
        {
            if(it<pivot)
            {
                res[low]=it;
                low++;
            }
            else if(it==pivot)
            {
                res[same]=it;
                same++;
            }
            else
            {
                res[high]=it;
                high++;
            }
        }
        return res;
    }
};