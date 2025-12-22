class Solution {
private:
    bool solve(vector<string>& strs, int n, int i, int j){
        for(auto x: strs){
            if(x[i] < x[j]) return false;
        }
        return true;
    }
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        vector<int> dp(m,1);

        int ans = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<i; j++){
                if(solve(strs,n,i,j)){
                    dp[i] = max(dp[i],dp[j]+1);
                    ans = max(ans,dp[i]);
                }
            }
        }
        return m - ans;
    }
}; 