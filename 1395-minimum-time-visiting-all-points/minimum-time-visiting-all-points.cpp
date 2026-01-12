class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();

        long long ans = 0;
        for(int i=1; i<n; i++){
            long long x1 = points[i-1][0];
            long long y1 = points[i-1][1];

            long long x2 = points[i][0];
            long long y2 = points[i][1];

            ans += max(abs(x1-x2),abs(y1-y2));
        }
        return ans;
    }
};