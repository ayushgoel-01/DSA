class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;
        for(auto i: s){
            if(i == ' ' || (i >= '0' && i <= '9')) continue;
            if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') v++;
            else c++;
        }
        if(c == 0) return 0;
        return floor(v/(double)c);
    }
};