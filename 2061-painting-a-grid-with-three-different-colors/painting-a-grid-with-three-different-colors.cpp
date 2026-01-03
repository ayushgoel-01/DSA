class Solution {
int mod = 1e9 + 7;
private:
    void getStates(string s, char prev, vector<string>& v, int m){
        if(m == 0){
            v.push_back(s);
            return;
        }

        for(auto ch: {'R','G','B'}){
            if(ch == prev) continue;
            getStates(s+ch,ch,v,m-1);
        }
    }
    int solve(vector<string>& v, int prev, int n, int m, vector<vector<int>>& dp){
        if(n == 0) return 1;

        if(dp[n][prev] != -1) return dp[n][prev];

        int ans = 0;
        for(int curr=0; curr<v.size(); curr++){
            if(curr == prev) continue;

            bool flag = false;
            for(int j=0; j<m; j++){
                if(v[prev][j] == v[curr][j]){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans = (ans + solve(v,curr,n-1,m,dp))%mod;
            }
        }
        return dp[n][prev] = ans;
    }

public:
    int colorTheGrid(int m, int n) {
        vector<string> v;
        getStates("",'#',v,m);

        int size = v.size();
        vector<vector<int>> dp(n+1, vector<int>(size,-1));
        int ans = 0;

        for(int i=0; i<size; i++){
            ans = (ans + solve(v,i,n-1,m,dp))%mod;
        }
        return ans;
    }
};