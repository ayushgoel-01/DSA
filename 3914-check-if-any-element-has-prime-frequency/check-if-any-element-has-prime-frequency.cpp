class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(101,0);

        for(auto i: nums) freq[i]++;

        vector<bool> isPrime(101,true);
        isPrime[0] = isPrime[1] = false;

        for(int i=2; i<sqrt(101); i++){
            for(int j=2; j<51; j++){
                if(i*j < 101 && isPrime[i*j]) isPrime[i*j] = false;
            }
        }

        for(auto i: freq){
            if(isPrime[i]) return true;
        }
        return false;
    }
};