class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int lCnt = 0, rCnt = 0;
        for(auto i: moves){
            if(i == 'L') lCnt++;
            else if(i == 'R') rCnt++;
        }

        return n - 2*min(lCnt,rCnt);
    }
};