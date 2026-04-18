class Solution {
public:
    int mirrorDistance(int n) {
        int x = n;
        int val = 0;
        while(x){
            val = val * 10 + (x%10);
            x /= 10;
        }
        return abs(n-val);
    }
};