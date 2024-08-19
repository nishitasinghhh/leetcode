class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int n=nums.size();
        int count=0;
        int el;
        for(int i=0; i<n; i++)
        {
            if(count==0)
            {
                count=1;
                el=nums[i];
            }
            else if(nums[i]==el) count++;
            else count--;
        }
        int cnt=0;
        int m=n/2;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==el)
                cnt++;
        }
        if(cnt>=m)
            
            return el;
        return -1;
    }
};
//Moore's Voting algorithm
//time complexity:- O(N)+O(N)
//space complexity:-O(1)
