class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for(auto i: s){
            if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') cnt++;
        }
        return cnt > 0;
    }
};