class Solution {
private:
    bool solve(int i, vector<int>& bits, int n){
        if(i >= n) return false;
        if(i == n-1) return bits[n-1] == 0;

        int op1 = false, op2 = false;
        if(bits[i] == 0){
            op1 = solve(i+1,bits,n);
        }
        else op2 = solve(i+2,bits,n);

        return op1 || op2;
    }
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if(n == 1) return true;
        
        return solve(0,bits,n);
    }
};