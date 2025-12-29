class Solution {
public:
    int minAllOneMultiple(int k) {
        int ans = 1, len = 1;
        while(ans % k != 0 && len <= k){
            len++;
            ans = (ans * 10 + 1) % k;
        }
        return (len <= k) ? len : -1;
    }
};