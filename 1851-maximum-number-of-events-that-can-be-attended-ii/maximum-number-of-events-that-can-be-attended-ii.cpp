class Solution {
private:
    int binarySearch(int start, vector<vector<int>>& events, int val){
        int end = events.size()-1;

        int ans = end+1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(events[mid][0] > val){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
    int solve(int i, vector<vector<int>>& events, int k, vector<vector<int>>& dp){
        if(i >= events.size() || k <= 0) return 0;

        if(dp[i][k] != -1) return dp[i][k];

        int take = events[i][2];
        // Binary Search to find next valid event
        int j = binarySearch(i+1,events,events[i][1]);
        take += solve(j,events,k-1,dp);

        int notTake = solve(i+1,events,k,dp);

        return dp[i][k] = max(take,notTake);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
        return solve(0,events,k,dp);
    }
};