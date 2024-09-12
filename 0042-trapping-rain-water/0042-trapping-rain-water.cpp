class Solution {
public:
    vector<int> findPrefixMax(vector<int> &heights)
    {
        int n=heights.size();
        vector<int>prefix(n);
        prefix[0]=heights[0];
        for(int i=1; i<heights.size(); i++)
        {
            prefix[i]=max(prefix[i-1],heights[i]);
        }
        return prefix;
    }
    vector<int> findSuffixMax(vector<int> &heights)
    {
        int n=heights.size();
        vector<int>suffix(n);
        suffix[n-1]=heights[n-1];
        for(int i=n-2; i>=0; i--)
        {
            suffix[i]=max(suffix[i+1],heights[i]);
        }
        return suffix;
    }
    int trap(vector<int>& heights) {
        int total=0;
        vector<int>prefixMax=findPrefixMax(heights);
            vector<int>suffixMax=findSuffixMax(heights);
        for(int i=0; i<heights.size(); i++)
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