class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        int n=s.size();
        for(int i=0; i<n; i++)
        {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                str+=s[i];
        }
        transform(str.begin(),str.end(), str.begin(), :: tolower);
        int i = 0, j = str.size() - 1;
        while(i <= j)
        {
            if(str[i] != str[j])
                return false;
            i++; j--;
        }
        return true;   
            
    }
};