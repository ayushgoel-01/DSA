class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        for(int i=0; i<n; i++){
            char ch = s[i];
            s += ch;
            if(s.substr(i+1) == goal) return true;
        }
        return false;
    }
};