class Solution {
public:
    int majorityElement(vector<int>& nums) {
     int n=nums.size();
        int cnt=0;
        int el=INT_MIN;
        for(int i=0; i<n; i++)
        {
            if(cnt==0)
            {
                cnt=1;
                el=nums[i];
            }
            else if(nums[i]==el) cnt++;
            else cnt--;
        }
        int count=0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==el)
            {
                count++;
            }
        }
        int m=n/2;
        if(count>=m) return el;
        return -1;
    }
};
//Moore's Voting algorithm
//time complexity:- O(N)+O(N)
//space complexity:-O(1)
