class Solution {
private:
    void solve(int open, int close, string temp, vector<string>& ans){
        if(open == 0 && close == 0){
            ans.push_back(temp);
            return;
        }

        if(close > 0 && close > open){
            temp += ")";
            solve(open,close-1,temp,ans);
            temp.pop_back();
        }
        if(open > 0){
            temp += "(";
            solve(open-1,close,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,n,"",ans);
        return ans;
    }
};