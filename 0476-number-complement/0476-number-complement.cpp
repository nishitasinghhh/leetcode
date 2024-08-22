
#include <cmath>

class Solution {
public:
    int findComplement(int num) {
        int i = 0, ans = 0;
        while (num > 0) {
            // Extract the last bit by taking the remainder of num divided by 2
            int temp = num % 2;
            // If the bit is 0, add 2^i to the result
            if (temp == 0) {
                ans += pow(2, i);
            }
            // Update num by dividing it by 2 (effectively shifting right)
            num = num / 2;
            i++;
        }
        return ans;
    }
};