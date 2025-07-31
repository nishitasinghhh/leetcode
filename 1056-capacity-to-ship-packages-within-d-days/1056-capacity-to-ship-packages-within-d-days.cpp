class Solution {
public:
int findTotalDaysToShip(vector<int>& weights, int mid)
{
    int day=1;
    int totalWeight=0;
    for(int i=0; i<weights.size(); i++)
    {
        if(totalWeight+weights[i]>mid)
        {
            day++;
            totalWeight=weights[i];
        }
        else
        {
            totalWeight+=weights[i];
        }
    }
    return day;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(findTotalDaysToShip(weights,mid)<=days)
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