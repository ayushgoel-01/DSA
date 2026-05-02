class Solution {
private:
    bool solve(int n){
        bool got = false;
        while(n){
            int digit = n%10;
            if(digit == 2 || digit == 5 || digit == 6 || digit == 9){
                got = true;
            }
            else if(digit == 3 || digit == 4 || digit == 7) return false;
            n = n / 10;
        }
        return got;
    }
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(solve(i)){
                ans++;
            }
        }
        return ans;
    }
};