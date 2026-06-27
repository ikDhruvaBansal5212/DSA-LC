class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        if (k == n)
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);

        int tsum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int ws=n-k;
        int windowsum=0;
        for(int i=0;i<ws;i++){
            windowsum+=cardPoints[i];
        }
        int l=0;
        int res=windowsum;
        for(int r=n-k;r<n;r++){
            windowsum=windowsum- cardPoints[l]+cardPoints[r];
            l++;

            res=min(res,windowsum);
        }
        return tsum-res;
    }
};