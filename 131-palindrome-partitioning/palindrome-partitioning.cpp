class Solution {
private:
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start] != s[end]) return false;
            start++; end--;
        }
        return true;
    }
private:
    void solve(int i, string& s, vector<string> ds, vector<vector<string>>& ans){
        if(i >= s.size()){
            ans.push_back(ds);
            return;
        }

        for(int idx=i; idx<s.size(); idx++){
            if(isPalindrome(s,i,idx)){
                ds.push_back(s.substr(i,idx-i+1));
                solve(idx+1,s,ds,ans);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> ans;

        solve(0,s,ds,ans);
        return ans;
    }
};