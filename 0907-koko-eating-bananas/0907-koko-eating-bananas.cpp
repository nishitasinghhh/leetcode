class Solution {
public:
int findTotalHours(vector<int>& piles,int k)
{
    int totalH = 0;
    int n = piles.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(piles[i]) / (double)(k));
    }
    return totalH;
}
int findMax(vector<int>& piles)
{
    int maxi=INT_MIN;
    for(int i=0; i<piles.size(); i++)
    {
        maxi=max(piles[i],maxi);
    }
    return maxi;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=findMax(piles);
        while(low<=high)
        {
            int mid=(low+high)/2;
            int totalHours=findTotalHours(piles,mid);
            if(totalHours<=h)
            high=mid-1;
            else
            low=mid+1;
        }
        return low;
    }
};