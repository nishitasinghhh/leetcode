class Solution {
public:
    void findLps(vector<int>&lps,string pat)
    {
        int pre=0;
        int suf=1;
        while(suf<pat.size())
        {
            if(pat[pre]==pat[suf])
            {
                lps[suf]=pre+1;
                pre++;
                suf++;
            }
            else
            {
                if(pre==0)
                {
                    lps[suf]=0;
                    suf++;
                }
                else
                {
                    pre=lps[pre-1];
                }
            }
        }
    }
    bool KMP_MATCH(string txt, string pat)
    {
        vector<int>lps(pat.size(),0);
        findLps(lps,pat);
        int first=0;
        int second=0;
        while(first<txt.size() && second<pat.size())
        {
            if(txt[first]==pat[second])
            {
                first++;
                second++;
            }
            else
            {
                if(second==0)
                {
                    first++;
                }
                else
                {
                    second=lps[second-1];
                }
            }
        }
        if(second==pat.size())
            return 1;
        return 0;
    }
    int repeatedStringMatch(string a, string b) {
        if(a==b)
            return 1;
        int repeat=1;
        string temp=a;
        while(temp.size()<b.size())
        {
            temp+=a;
            repeat++;
        }
        if(KMP_MATCH(temp,b))
            return repeat;
        if(KMP_MATCH(temp+a,b))
            return repeat+1;
        return -1;
        
    }
};