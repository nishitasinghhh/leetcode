class Solution {
public:
    string removeKdigits(string nums, int k) {
        if(nums.size()==0)
        return "0";
        string result;
         int n=nums.size();
         for(int i=0; i<n; i++)
         {
            while(!result.empty() && k>0 && (nums[i]-'0')<(result.back()-'0'))
            {
result.pop_back();
k--;
            }
            if(result.empty() && nums[i]=='0')
                continue;
            result.push_back(nums[i]);
         }
          while(!result.empty() && k)
        {
            result.pop_back();
            k--;
        }
        if(result.empty()) return "0";
        return result;
    }
};