class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int left=0;
        int right=0;
        if(n==0)
            return;
        vector<int>ans(m+n,0);
        int k=0;
        while(left<m && right<n)
        {
            if(nums1[left]<=nums2[right])
            {
                ans[k]=nums1[left];
                k++;
                left++;
            }
            else
            {
                ans[k]=nums2[right];
                k++;
                right++;
            }
        }
        while(left<m)
        {
             ans[k]=nums1[left];
                k++;
                left++;
        }
        while(right<n)
        {
             ans[k]=nums2[right];
                k++;
                right++;
        }
        nums1=ans;        
    }
};