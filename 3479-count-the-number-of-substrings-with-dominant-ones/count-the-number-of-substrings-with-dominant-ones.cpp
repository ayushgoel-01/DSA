class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        vector<int> pref(n,0);
        pref[0] = s[0] - '0';
        for(int i=1; i<n; i++){
            pref[i] = pref[i-1] + (s[i] - '0');
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int ones = pref[j];
                if(i-1 >= 0) ones -= pref[i-1];

                int zeroes = (j-i+1) - ones;

                if((zeroes * zeroes) > ones) j += (zeroes * zeroes) - ones-1;
                else{
                    ans++;

                    if((zeroes * zeroes) < ones){
                        int diff = sqrt(ones) - zeroes;
                        int nextj = j + diff;

                        if(nextj >= n) ans += n-j-1;
                        else ans += diff;

                        j = nextj;
                    }
                }
            }
        }
        return ans;
    }
};