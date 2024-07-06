class Solution {
public:
int findOutK(int mid,int h,vector<int>& piles)
{
    long long totalH=0;
    int n=piles.size();
    for(int i=0; i<n; i++)
    {
        totalH+=ceil((double)(piles[i])/(double)(mid));
    }
    if(totalH<=h) return 1;
     return 0;
}
int findMax(vector<int>& piles)
{
    int maxi=INT_MIN;
    for(int i=0; i<piles.size(); i++)
    {
        maxi=max(maxi,piles[i]);
    }
    return maxi;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=findMax(piles);
        
        while(low<=high)
        {
           int mid=low+(high-low)/2;
            if(findOutK(mid,h,piles))
            {   
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
        
    }
};
//time complexity:- O(logn+O(n)+O(n))
//space complexity:-O(1)