class Solution {
public:
    string largestEven(string s) {
        int n = s.size();
        if(s[n-1] == '2') return s;

        int i = n-1;
        while(i >= 0 && s[i] == '1'){
            i--;
        }

        if(i < 0) return "";
        return s.substr(0,i+1);
    }
};