class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>>mpp;
        for(int i=0; i<strs.size(); i++)
        {
            string s=strs[i];
            sort(s.begin(),s.end());
            mpp[s].push_back(strs[i]);
        }
        for(auto it:mpp)
        {
            result.push_back(it.second);
        }
        return result;
    }
};
//time :-O(N*(SlogS));
//space:-O(N*S)