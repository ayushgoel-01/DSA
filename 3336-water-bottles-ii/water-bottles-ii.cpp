class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = 0;
        int ans = 0;
        int extra = numBottles;

        while(extra + empty >= numExchange){
            if(empty >= numExchange){
                empty -= numExchange;
                numExchange++;
                extra++;
            }
            else{
                empty += extra;
                ans += extra;
                extra = 0;
            }
        }
        ans += extra;
        return ans;
    }
};