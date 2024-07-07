class Solution {
public:
    bool bloomDayPossible(vector<int>& bloomDay,int m,int k,int mid)
    {
        int cnt=0;
        int no_of_b=0;
        for(int i=0; i<bloomDay.size(); i++)
        {
            if(bloomDay[i]<=mid)
            {
                cnt++;
            }
            else
            {
                no_of_b+=(cnt/k);
                cnt=0;
            }
        }
         no_of_b+=(cnt/k);
        if(no_of_b>=m)
            return true;
        return false;
    }
    int findMax(vector<int>& bloomDay)
    {
        int maxi=INT_MIN;
        for(int i=0; i<bloomDay.size(); i++)
        {
              maxi=max(maxi,bloomDay[i]);
        }
      return maxi;
    }
int findMin(vector<int>& bloomDay)
{
    int mini=INT_MAX;
    for(int i=0; i<bloomDay.size(); i++)
    {
        mini=min(mini,bloomDay[i]);
    }
    return mini;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=1ll*m *1ll*k;
        int n=bloomDay.size();
        if(val>n) return -1;
        int low=findMin(bloomDay);
        int high=findMax(bloomDay);
        while(low<=high)
        {
           int mid=(low+high)/2;
            if(bloomDayPossible(bloomDay,m,k,mid))
            {
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return low;
    }
};