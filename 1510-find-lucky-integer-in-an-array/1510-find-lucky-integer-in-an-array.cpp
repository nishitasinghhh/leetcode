class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mpp;
        int n=arr.size();
        for(int i=0; i<n; i++)
        {
            mpp[arr[i]]++;
        }
        int maxi=-1;
        for(auto it:mpp)
        {
            if(it.first==it.second)
            {
                maxi=max(maxi,it.first);
            }
        }
        return maxi;
    }
};