class Solution {
private:
    bool solve(int a, int b){
        while(a){
            int digit = a % 10;
            if(digit == 0) return false;
            a /= 10;
        }

        while(b){
            int digit = b % 10;
            if(digit == 0) return false;
            b /= 10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1; i<n; i++){
            for(int j=1; j<n; j++){
                if(i+j == n && solve(i,j)){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};