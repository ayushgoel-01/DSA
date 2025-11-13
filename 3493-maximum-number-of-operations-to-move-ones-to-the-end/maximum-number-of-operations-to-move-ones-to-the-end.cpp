class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();

        int ans = 0, val = 0, cnt = 0;
        int i = n-1;
        while(i >= 0 && s[i] == '1') i--;

        int j = i;
        while(j >= 0){
            if(s[j] == '1'){
                while(j >= 0 && s[j] == '1'){
                    cnt++;
                    j--;
                }
                ans += cnt * val;
                cnt = 0;
            }
            else{
                val++;
                while(j >= 0 && s[j] == '0') j--;
            }
        }
        ans += cnt * val;
        return ans;
    }
};