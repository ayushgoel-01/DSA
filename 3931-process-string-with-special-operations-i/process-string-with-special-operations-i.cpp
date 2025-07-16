class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string ans = "";

        for(auto i: s){
            if(i == '*'){
                if(!ans.empty()) ans.erase(ans.size()-1);
            }
            else if(i == '#'){
                ans += ans;
            }
            else if(i == '%'){
                reverse(ans.begin(),ans.end());
            }
            else{
                ans += i;
            }
        }
        return ans;
    }
};