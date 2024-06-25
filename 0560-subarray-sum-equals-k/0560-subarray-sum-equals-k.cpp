class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int prefixSum=0;
        int cnt=0;
        unordered_map<int,int>mpp; //<prefixSum,count>
        mpp[0]=1;  //(0,1)
        for(int i=0; i<n; i++)
        {
            prefixSum+=nums[i];
            int remove=prefixSum-k;  
            cnt+=mpp[remove];
            mpp[prefixSum]+=1;
        }
        return cnt;
        
    }
};
//timexompleity:- O(N);
//space complexity:-O(N)