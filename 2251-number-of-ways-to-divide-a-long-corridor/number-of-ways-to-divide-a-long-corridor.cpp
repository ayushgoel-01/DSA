class Solution {
int mod = 1e9 + 7;
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        
        int cnt = 0;
        for(auto i: corridor) cnt += (i == 'S');

        if(cnt % 2 == 1 || cnt <= 1) return 0;
        
        vector<int> v;
        for(int i=0; i<n; i++){
            if(corridor[i] == 'S') v.push_back(i);
        }

        int ans = 1;
        for(int i=2; i<v.size(); i+=2){
            if(ans == 1) ans = v[i] - v[i-1];
            else ans = (ans * 1LL * (v[i]-v[i-1])%mod)%mod;
        }
        return ans;
    }
};