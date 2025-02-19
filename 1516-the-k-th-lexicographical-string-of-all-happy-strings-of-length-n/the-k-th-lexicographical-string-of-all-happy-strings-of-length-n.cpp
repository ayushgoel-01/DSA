class Solution {
private:
    void solve(int n, string temp, vector<string>& ans){
        if(n <= 0){
            ans.push_back(temp);
            return;
        }

        if(temp.empty() || temp.back() != 'a'){
            solve(n-1,temp+"a",ans);
        }
        if(temp.empty() || temp.back() != 'b'){
            solve(n-1,temp+"b",ans);
        }
        if(temp.empty() || temp.back() != 'c'){
            solve(n-1,temp+"c",ans);
        }

    }
public:
    string getHappyString(int n, int k) {
        vector<string> ans;

        solve(n,"",ans);
        sort(ans.begin(),ans.end());
        return ans.size() >= k ? ans[k-1] : "";
    }
};