class Solution {
int mod = 1e9 + 7;
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        
        vector<int> v;
        for(int i=0; i<n; i++){
            if(corridor[i] == 'S') v.push_back(i);
        }

        int size = v.size();
        if(size % 2 == 1 || size == 0) return 0;

        int ans = 1;
        for(int i=2; i<v.size(); i+=2){
            ans = (ans * 1LL * (v[i]-v[i-1])%mod)%mod;
        }
        return ans;
    }
};