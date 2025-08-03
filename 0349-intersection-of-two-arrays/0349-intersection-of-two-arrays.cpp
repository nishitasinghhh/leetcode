class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st(nums1.begin(),nums1.end());
        unordered_set<int>result;
        for(int i=0; i<nums2.size(); i++)
        {
            if(st.find(nums2[i])!=st.end())
            {
                result.insert(nums2[i]);
            }
        }
        return vector<int>(result.begin(),result.end());
    }
};