class Solution {
public:
    
   vector<int> findPrefixMax(vector<int> heights,int n)
   {
     
       vector<int>prefix_max(n);
       prefix_max[0]=heights[0];
       for(int i=1; i<n; i++)
       {
           prefix_max[i]=max(prefix_max[i-1],heights[i]);
       }
       return prefix_max;
       
   }
    vector<int> findSuffixMax(vector<int> heights,int n)
    {
        vector<int>suffix_max(n);
        suffix_max[n-1]=heights[n-1];
        for(int i=n-2; i>=0; i--)
        {
            suffix_max[i]=max(suffix_max[i+1],heights[i]);
        }
        return suffix_max;
    }
    int trap(vector<int>& heights) {
      int total=0;
        int n=heights.size();
        vector<int>prefixMax=findPrefixMax(heights,n);
        vector<int>suffixMax=findSuffixMax(heights,n);
        for(int i=0; i<n; i++)
        {
            int leftMax=prefixMax[i];
            int rightMax=suffixMax[i];
            if(heights[i]<leftMax && heights[i]<rightMax)
            {
                total+=min(leftMax,rightMax)-heights[i];
            }
        }
        return total;
    }
};