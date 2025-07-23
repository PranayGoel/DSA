class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = 0, r = n-1;
        int maxPoints = 0, sum = 0;
        int count = 0;

        for(int i = 0; i < k; i++){
            sum += cardPoints[i];
        }
        l = k -1;
        maxPoints = sum;
        while(r > n-k-1){
            sum -= cardPoints[l--];
            sum += cardPoints[r--];
            maxPoints = max(maxPoints, sum);

        }
        return maxPoints;
    }
};