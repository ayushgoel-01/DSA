class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();

        long long l = 0, lc = 0, lct = 0;
        for(auto i: s){
            if(i == 'L') l++;
            else if(i == 'C') lc += l;
            else if(i == 'T') lct += lc;
        }

        vector<long long> suffixT(n+1,0), suffixCT(n+1,0);
        for(int i=n-1; i>=0; i--){
            suffixT[i] += suffixT[i+1];
            suffixCT[i] += suffixCT[i+1];

            if(s[i] == 'T') suffixT[i]++;
            // Each C forms CT with T
            if(s[i] == 'C') suffixCT[i] += suffixT[i];
        }

        long long extra = 0, prefixL = 0, prefixLC = 0;
        for(int i=0; i<=n; i++){
            // Insert L
            extra = max(extra,suffixCT[i]);

            // Insert C
            extra = max(extra,prefixL * suffixT[i]);

            // Insert T
            extra = max(extra,prefixLC);

            if(i < n){
                if(s[i] == 'L') prefixL++;
                else if(s[i] == 'C') prefixLC += prefixL;
            }
        }
        return lct + extra;
    }
};