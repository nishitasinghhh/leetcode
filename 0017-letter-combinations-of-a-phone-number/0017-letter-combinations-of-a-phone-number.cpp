class Solution {
public:
void solve(string digits, string mapping[], int index, string output, vector<string> &ans)
{
    if(index>=digits.size())
    {
        ans.push_back(output);
        return;
    }
    int num=digits[index]-'0';
    string value=mapping[num];
    for(int i=0; i<value.size(); i++)
    {
        output.push_back(value[i]);
        solve(digits,mapping,index+1,output,ans);
        output.pop_back();
    }
    
}

    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string output;
        int index=0;
        if(digits.size()==0)
            return ans;
        string mapping[10]={"","", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,mapping,index,output,ans);
        return ans;  
    }
};