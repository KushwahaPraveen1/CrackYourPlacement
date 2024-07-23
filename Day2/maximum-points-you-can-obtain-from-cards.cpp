class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
     int sum=0;
     int lsum=0,rsum=0;
     for(int i=0;i<k;i++)
     lsum+=cardPoints[i];
     sum=lsum;
     int right=cardPoints.size()-1;
     for(int i=k-1;i>=0;i--)
     {
        lsum=lsum-cardPoints[i];
        rsum=rsum+cardPoints[right];
        right--;
        sum=max(sum,lsum+rsum);
     }return sum;
    }
};