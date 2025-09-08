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
        for(int i=1; i<(n/2)+1; i++){
                int num1 = i;
                int num2 = n-i;
                if(num1 + num2 == n && solve(num1,num2)){
                    return {num1,num2};
                }
        }
        return {0,0};
    }
};