class Solution {
public:
    int findLast(vector<int>& nums, int target)
    {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int last=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return last;
    }
    int findFirst(vector<int>& nums, int target)
    {   int n=nums.size();
        int low=0;
        int high=n-1;
     int first=-1;
     while(low<=high)
     {
         int mid=(low+high)/2;
         if(nums[mid]==target){
             first=mid;
             high=mid-1;
         }
         else if(nums[mid]<target)
         {
             low=mid+1;
         }
         else
         {
             high=mid-1;
         }
     }
     return first;
    }
vector<int> searchRange(vector<int>& nums, int target) {
      int first=findFirst(nums,target);
    if(first==-1)
        return {-1,-1};
    int last=findLast(nums,target);
    return {first,last};
    }
};
//time complexity:-O(2*log(n));
//space complexity:-O(1)