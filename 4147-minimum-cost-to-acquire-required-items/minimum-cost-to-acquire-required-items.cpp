class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long op1 = (need1 * 1LL * cost1) +  (need2 * 1LL * cost2);
        long long op2 = max(need1,need2) * 1LL * costBoth;

        long long both = min(need1,need2);
        long long op3 = costBoth * 1LL * both;

        long long rem = 0;
        if(both == need1){
            rem = need2 - both;
            op3 += min(rem * 1LL * cost2,rem * 1LL * costBoth);
        }
        else{
            rem = need1 - both;
            op3 += min(rem * 1LL * cost1,rem * 1LL * costBoth);
        }
        return min({op1,op2,op3});
    }
};