class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        int yCnt = 0;
        for(auto i: customers){
            yCnt += i == 'Y';
        }

        if(yCnt == 0) return 0;
        if(yCnt == n) return n;

        int ans = INT_MAX, val = INT_MAX;
        int nCnt = 0;
        for(int i=0; i<n; i++){
            if(nCnt + yCnt < val){
                val = nCnt + yCnt;
                ans = i;
            }

            if(customers[i] == 'N') nCnt++;
            else yCnt--;
        }
        if(nCnt + yCnt < val){
            ans = n;
        }
        return ans;
    }
};