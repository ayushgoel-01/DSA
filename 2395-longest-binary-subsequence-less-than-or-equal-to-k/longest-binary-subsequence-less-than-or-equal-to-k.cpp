class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();

        long long val = 0, ans = 0;
        for(int i=n-1; i>=0; i--){
            int x = s[i] - '0';

            if(x == 1){
                if(val+(pow(2,n-i-1)) <= k){
                    val += pow(2,n-i-1);
                    ans++;
                }
            }
            else ans++;
        }
        return ans;
    }
};