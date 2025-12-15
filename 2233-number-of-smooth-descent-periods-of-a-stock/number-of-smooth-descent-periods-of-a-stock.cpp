class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();

        long long ans = 0;
        int j = 0, cnt = 0;

        while(j < n){
            if(j == 0) cnt++;
            else if(prices[j-1] - prices[j] == 1){
                cnt++;
            }
            else{
                cnt = 1;
            }
            ans += cnt;
            j++;
        }
        return ans;
    }
};