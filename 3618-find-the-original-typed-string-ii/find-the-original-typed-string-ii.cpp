class Solution {            // Optimized Tabulation (Using Prefix sum)
int M = 1e9+7;
public:
    int possibleStringCount(string word, int k) {
        int n = word.size();
        if(k > n) return 0;

        vector<int> freq;
        int cnt = 1;

        for(int i=1; i<n; i++){
            if(word[i] == word[i-1]) cnt++;
            else{
                freq.push_back(cnt);
                cnt = 1;
            }
        }
        freq.push_back(cnt);

        long long p = 1;
        for(auto i: freq){
            p = (1LL * p * i) % M;
        }

        if(freq.size() >= k) return p;

        int m = freq.size();

        vector<vector<int>> dp(m+1, vector<int>(k+1,0));
        for(int cnt=k-1; cnt>=0; cnt--){
            dp[m][cnt] = 1;
        }

        for(int i=m-1; i>=0; i--){

            vector<int> pref(k+1,0);
            for(int h=1; h<=k; h++){            // 1 Based indexing
                pref[h] = (pref[h-1] + dp[i+1][h-1]) % M;
            }

            for(int cnt=k-1; cnt>=0; cnt--){
                int l = cnt+1;
                int r = cnt+freq[i];

                if(r+1 > k) r = k-1;

                if(l <= r){
                    dp[i][cnt] = (pref[r+1] - pref[l] + M) % M;
                }
            }
        }
        return (p - dp[0][0] + M) % M;
    }
};