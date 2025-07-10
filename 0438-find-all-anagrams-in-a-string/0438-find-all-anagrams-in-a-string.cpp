class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length()<p.length())
        return {};
        vector<int>res;
        vector<int>pFreq(26,0),sFreq(26,0);
        for(char c:p)
        pFreq[c-'a']++;
        int i=0;
        for(int j=0; j<s.length(); j++)
        {
            sFreq[s[j]-'a']++;
            if(j-i+1<p.size())
            continue;
            if(sFreq==pFreq)
            res.push_back(i);
            sFreq[s[i]-'a']--;
            i++;
        }
        return res;
    }
};