class Solution {
public:
    long long flowerGame(int n, int m) {
        long long even1 = n/2, even2 = m/2;
        long long odd1 = (n+1)/2, odd2 = (m+1)/2;

        long long ans = even1 * odd2;
        ans = ans + (even2 * odd1);
        return ans;
    }
};