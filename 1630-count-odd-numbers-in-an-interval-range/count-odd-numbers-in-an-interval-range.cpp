class Solution {
public:
    int countOdds(int low, int high) {
        int mid = (high-low+1)/2;

        if(low % 2 == 1 && high % 2 == 1) return mid+1;
        return mid;
    }
};