class Solution {
private:
    bool solve(int n){
        int firstBit = (n & 1);
        n = n >> 1;
        while(n){
            if((n & 1) != firstBit) return false;
            n = n >> 1;
        }
        return true;
    }
public:
    int countMonobit(int n) {
        int ans = 0;
        for(int i=0; i<=n; i++){
            ans += solve(i);
        }
        return ans;
    }
};