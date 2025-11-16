class Solution {
int mod = 1e9 + 7;
public:
    int numSub(string s) {
        int n = s.size();

        long long ans = 0;
        long long i = 0, cnt = 0;
        while(i < n){
            while(i < n && s[i] == '1'){
                cnt++;
                i++;
            }
            ans = (ans + (cnt%mod * 1LL * (cnt+1)%mod)%mod/2)%mod;
            cnt = 0;
            i++;
        }
        ans = (ans + (cnt%mod * 1LL * (cnt+1)%mod)%mod/2)%mod;
        return ans;
    }
};