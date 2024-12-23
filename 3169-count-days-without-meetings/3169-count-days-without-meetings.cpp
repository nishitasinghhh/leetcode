class Solution {
public:
    bool static comp(vector<int> &a, vector<int> &b)
    {
        return a[0]<b[0];
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        vector<vector<int>>ans;
        sort(meetings.begin(),meetings.end(),comp);
        for(int i=0; i<n; i++)
        {
            if(ans.empty() || meetings[i][0]>ans.back()[1])
            {
                ans.push_back(meetings[i]);
            }
            else
            {
                ans.back()[1]=max(ans.back()[1],meetings[i][1]);
            }
        }
        int count=0;
        for(auto it:ans)
        {
            days-=(it[1]-it[0]+1);
        }
        return (days);
    }
};