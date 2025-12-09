class Solution {
private:
    bool checkPrime(int n){
        if(n == 0 || n == 1) return false;

        int val = sqrt(n);
        for(int i=2; i<=val; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
public:
    bool completePrime(int num) {
        string s = to_string(num);

        int size = s.size();
        string temp1 = "", temp2 = "";

        for(int i=0; i<size; i++){
            temp1 += s[i];
            temp2 = s[size-i-1] + temp2;

            int val1 = stoi(temp1);
            int val2 = stoi(temp2);

            if(checkPrime(val1) == false || checkPrime(val2) == false) return false;
        }
        return true;
    }
};