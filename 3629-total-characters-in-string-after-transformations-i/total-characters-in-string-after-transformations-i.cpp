class Solution {
int MOD = 1e9 + 7;
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> freq(26,0);
        for(auto i: s){
            freq[i-'a']++;
        }

        while(t--){
            int last = freq[25];
            for(int i=25; i>=1; i--){
                freq[i] = freq[i-1];
            }
            freq[0] = last;
            freq[1] = (freq[1] + last) % MOD;
        }
        int ans = 0;
        for(auto i: freq) ans = (ans + i) % MOD;
        return ans;
    }
};