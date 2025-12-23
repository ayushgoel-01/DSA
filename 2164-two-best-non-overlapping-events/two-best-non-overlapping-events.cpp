class Solution {
private:
    int binarySearch(vector<vector<int>>& events, int val, int n){
        int start = 0, end = n-1;
        int ans = n;

        while(start <= end){
            int mid = start + (end - start)/2;
            if(events[mid][0] > val){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
    int solve(int i, vector<vector<int>>& events, int cnt, int n, vector<vector<int>>& dp){
        if(i >= n || cnt >= 2) return 0;

        if(dp[i][cnt] != -1) return dp[i][cnt];

        int nextIdx = binarySearch(events,events[i][1],n);
        int take = events[i][2] + solve(nextIdx,events,cnt+1,n,dp);
        int notTake = solve(i+1,events,cnt,n,dp);

        return dp[i][cnt] = max(take,notTake);
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n, vector<int>(3,-1));
        return solve(0,events,0,n,dp);
    }
};