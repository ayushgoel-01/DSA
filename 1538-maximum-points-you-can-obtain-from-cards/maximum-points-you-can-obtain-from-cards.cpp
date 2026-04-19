class Solution {
#define ll long long
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int ans = 0, sum = 0;
        for(int i=n-k; i<n; i++){
            sum += cardPoints[i];
        }
        ans = sum;
        
        int j = n-k;
        for(int i=0; i<k; i++){
            sum -= cardPoints[j++];
            sum += cardPoints[i];
            ans = max(ans,sum);
        }
        return ans;
    }
};