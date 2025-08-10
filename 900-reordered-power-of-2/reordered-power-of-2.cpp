class Solution {            // Using Digit Count
private:
    vector<int> solve(int n){
        vector<int> v(10,0);
        while(n){
            v[n%10]++;
            n = n/10;
        }
        return v;
    }
public:
    bool reorderedPowerOf2(int n) {
        vector<int> v = solve(n);

        for(int i=0; i<=29; i++){
            if(v == solve((1 << i))) return true;
        }
        return false;
    }
};