class Solution {
private:
    void solve(vector<int>& cnt, vector<string>& bank, int n){
        for(int i=0; i<n; i++){
            int val = 0;
            for(auto& j: bank[i]){
                if(j == '1') val++;
            }
            cnt[i] = val;
        }
    }
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();

        vector<int> cnt(n,0);
        solve(cnt,bank,n);

        int ans = 0;
        int prev = 0;
        while(prev < n && cnt[prev] <= 0){
            prev++;
        }
        int curr = prev+1;

        while(curr < n){
            if(cnt[curr] <= 0){
                curr++;
                continue;
            }
            else{
                ans += cnt[prev] * cnt[curr];
                prev = curr;
                curr++;
            }
        }
        return ans;
    }
};