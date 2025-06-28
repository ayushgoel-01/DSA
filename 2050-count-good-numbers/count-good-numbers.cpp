class Solution {            // Using Binary Exponentiation
int mod = 1e9+7;
#define ll long long
private:
    ll findPower(ll a, ll b){
        if(b == 0) return 1;

        ll half = findPower(a,b/2) % mod;
        ll ans = (half * half) % mod;

        if(b % 2 == 1){
            ans = (ans * a) % mod;
        }
        return ans%mod;
    }
public:
    int countGoodNumbers(long long n) {
        // Permutation and Combination of Even * Odd
        return (ll) (findPower(5,(n+1)/2) * findPower(4,n/2)) % mod;
    }
};