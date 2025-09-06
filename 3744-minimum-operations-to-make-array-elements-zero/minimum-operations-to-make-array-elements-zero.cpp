class Solution {
#define ll long long
private:
    ll solve(ll l, ll r){
        ll L = 1;
        int steps = 1;

        ll ans = 0;
        while(L <= r){
            ll R = 4 * L - 1;
            ll start = max(l,L);
            ll end = min(r,R);

            if(start <= end){
                ans += (end-start+1) * steps;
            }
            L = L * 4;
            steps++;
        }
        return ans;
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        int n = queries.size();

        ll ans = 0;
        for(auto& it: queries){
            ll l = it[0];
            ll r = it[1];

            ll steps = solve(l,r);
            ans += (steps+1)/2;         // Taking ceil by doing +1
        }
        return ans;
    }
};