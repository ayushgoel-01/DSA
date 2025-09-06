class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        int n = queries.size();

        long long ans = 0;
        for(auto& it: queries){
            long long l = it[0];
            long long r = it[1];
            int steps = 1;

            long long L = 1, R = 3;
            long long a = max(l,L);
            long long b = min(r,R);

            long long val = 0;
            while(L <= r){
                a = max(l,L);
                b = min(r,R);

                if(a > b){
                    L = L * 4;
                    R = ((R+1) * 1LL * 4)-1;
                    steps++;
                    continue;
                }
                int num = (b-a)+1;
                val = val + ((num * 1LL * steps));

                L = L * 4;
                R = ((R+1) * 1LL * 4)-1;
                steps++;
            }
            ans += ceil((double)val/2);
        }
        return ans;
    }
};