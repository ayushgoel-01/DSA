class Solution {
public:
    int findClosest(int x, int y, int z) {
        int val1 = abs(z-x);
        int val2 = abs(z-y);

        if(val1 == val2) return 0;
        return val1 < val2 ? 1 : 2;
    }
};