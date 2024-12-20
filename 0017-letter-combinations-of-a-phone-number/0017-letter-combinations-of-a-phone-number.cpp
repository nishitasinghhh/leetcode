class Solution {
public:

void solve(int index, string digits,vector<string>&ans,string mapp[],string output )
{
    if(index>=digits.size())
    {
        ans.push_back(output);
        return;
    }
    int num=digits[index]-'0';
    string val=mapp[num];
    for(int i=0; i<val.size(); i++)
    {
        output.push_back(val[i]);
        solve(index+1,digits,ans,mapp,output);
        output.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0)
            return ans;
        string mapp[10]={""," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string output;
        solve(0,digits,ans,mapp,output);
        return ans;
    }
};