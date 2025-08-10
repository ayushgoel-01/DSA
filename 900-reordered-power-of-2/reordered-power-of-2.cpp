class Solution {
private:
    string getSorted(int n){
        string s = to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
public:
    bool reorderedPowerOf2(int n) {
        string s = getSorted(n);

        long long num = 1;
        while(num < 1e9){
            if(s == getSorted(num)) return true;
            num = num * 2;
        }
        return false;
    }
};