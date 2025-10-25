class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int cnt = 0, start = 1, amt = 1;

        while(n--){
            ans += amt;
            cnt++;
            amt++;
            if(cnt >= 7){
                cnt = 0;
                start++;
                amt = start;
            }
        }
        return ans;
    }
};