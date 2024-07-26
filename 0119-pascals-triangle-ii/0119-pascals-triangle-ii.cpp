class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>result;
        long long ans=1;
        result.push_back(ans);
        for(int i=0; i<rowIndex; i++)
        {
            ans=ans*(rowIndex-i);
            ans=ans/(i+1);
            result.push_back(ans);
        }
        return result;
    }
};
//time complexity:-O(rowIndex)
//space complexity:-O(1)