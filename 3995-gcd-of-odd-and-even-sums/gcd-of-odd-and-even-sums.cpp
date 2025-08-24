class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = 1, even = 2;
        long long sum1 = odd, sum2 = even;

        for(int i=0; i<n-1; i++){
            odd += 2;
            even += 2;

            sum1 += odd;
            sum2 += even;
        }
        return __gcd(sum1,sum2);
    }
};