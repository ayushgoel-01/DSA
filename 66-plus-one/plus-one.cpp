class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        int sum = digits[n-1] + 1;
        int digit = sum % 10;
        int carry = sum / 10;

        digits[n-1] = digit;
        for(int i=n-2; i>=0; i--){
            sum = digits[i] + carry;
            digit = sum % 10;
            carry = sum / 10;

            digits[i] = digit;
            if(carry == 0) break;
        }

        if(carry){
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }
};