class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int t = 0;
        while(true){
            long long val = (long long)num1 - t * 1LL * num2;

            if(val < 0) return -1;

            // Calculate no. of set bits
            if(__builtin_popcountll(val) <= t && t <= val) return t;
            t++;
        }
        return -1; 
    }
};

/*  Simplify the equation:- 
    num11 = num1 - 2^i1 + num2
    num12 = num11 - 2^i2 + num2  =>  num12 = (num1 - 2^i1 + num2) - 2^i2 + num2
    num13 = num12 - 2^i3 + num2  =>  num13 = ((num1 - 2^i1 + num2) - 2^i2 + num2) - 2^i3 + num2

    0 = num1 - (2^i1 + 2^i2 + 2^i3 + ... 2^it) - t*num2
    num1 - t*num2 = 2^i1 + 2^i2 + 2^i3 + ... 2^it
    val = sum of t powers of 2

To find that in how many powers of 2 a number can be represented, just calculate no. of set bits
*/