class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ls=0;
        int rs=0;
        int maxSum=0;
        for(int i=0; i<k; i++)
        {
            ls+=cardPoints[i];
        }
        maxSum=ls;
        int n=cardPoints.size();
        int rightIndex=n-1;
        for(int i=k-1; i>=0; i--)
        {
            ls-=cardPoints[i];
            rs+=cardPoints[rightIndex];
            rightIndex--;
            maxSum=max(maxSum,ls+rs);
        }
        return maxSum;
    }
};