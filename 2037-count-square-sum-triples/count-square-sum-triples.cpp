class Solution {
public:
    int countTriples(int n) {
        int ans = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                for(int k=max(i,j)+1; k<=n; k++){
                    long long val1 = i * 1LL * i;
                    long long val2 = j * 1LL * j;
                    long long val3 = k * 1LL * k;

                    if(val1 + val2 == val3) ans++;
                }
            }
        }
        return ans;
    }
};