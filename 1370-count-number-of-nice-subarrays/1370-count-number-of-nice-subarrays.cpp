class Solution {
public:
int find(vector<int>& nums, int k)
{
    if(k<0)
    return 0;
    int l=0,r=0,sum=0,count=0;
    while(r<nums.size())
    {
        sum+=(nums[r]%2);
        while(sum>k)
        {
            sum-=(nums[l]%2);
            l++;
        }
         count+=(r-l+1);
         r++;
    }
    return count;

}
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=find(nums,k)-find(nums,k-1);
        return ans;
    }
};