class Solution {
private:
    bool isChar(char ch){
        return ch >= 'a' && ch <= 'z';
    }

    void solve(string& s, bool special){
        int i = 0, j = s.size()-1;
        while(i < j){
            if(special){
                if(!isChar(s[i]) && !isChar(s[j])){
                    swap(s[i],s[j]);
                    i++; j--;
                }
                else if(isChar(s[i])) i++;
                else j--;
            }
            else{
                if(isChar(s[i]) && isChar(s[j])){
                    swap(s[i],s[j]);
                    i++; j--;
                }
                else if(!isChar(s[i])) i++;
                else j--;
            }
        }
    }
public:
    string reverseByType(string s) {
        int n = s.size();
        solve(s,false);
        solve(s,true);
        return s;
    }
};