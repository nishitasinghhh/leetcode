class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mpp;
        for(auto i:knowledge)
        {
            mpp[i[0]]=i[1];
        }
        string ans;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(')
            {
                int j=i+1;
                while(s[j]!=')')
                {
                    j++;
                }
                string temp=s.substr(i+1,j-i-1);
                if(mpp.find(temp)!=mpp.end())
                {
                    ans+=mpp[temp];
                }
                else
                {
                    ans+='?';
                }
                i=j;
            }
            else
            {
                ans+=s[i];
            }
        }
        return ans;
    }
};