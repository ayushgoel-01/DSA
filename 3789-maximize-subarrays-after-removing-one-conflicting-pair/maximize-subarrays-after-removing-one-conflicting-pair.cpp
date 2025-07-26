class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        unordered_map<int,vector<int>> mp;

        for(auto& it: conflictingPairs){
            int a = min(it[0],it[1]);
            int b = max(it[0],it[1]);

            mp[b].push_back(a);
        }

        vector<long long> extra(n+1,0);
        long long valid = 0;
        int maxConflict = 0, secondMaxConflict = 0;

        for(int end=1; end<=n; end++){

            for(auto& u: mp[end]){
                if(u >= maxConflict){
                    secondMaxConflict = maxConflict;
                    maxConflict = u;
                }
                else if(u >= secondMaxConflict){
                    secondMaxConflict = u;
                }
            }
            valid += end - maxConflict;
            extra[maxConflict] += maxConflict - secondMaxConflict;
        }
        return valid + *max_element(extra.begin(),extra.end());
    }
};