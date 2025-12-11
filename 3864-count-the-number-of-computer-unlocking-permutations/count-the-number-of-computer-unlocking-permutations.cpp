class Solution {
int mod = 1e9 + 7;
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int ans = 1;
        for(int i=1; i<n; i++){
            if(complexity[i] <= complexity[0]) return 0;
            ans = (ans * 1LL * i) % mod;
        }
        return ans;
    }
};