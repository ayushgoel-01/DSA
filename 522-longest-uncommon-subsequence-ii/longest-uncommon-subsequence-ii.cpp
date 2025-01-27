class Solution {
private:
    void solve(int i, string& s, string temp, vector<string>& ans){
        if(i >= s.size()){
            ans.push_back(temp);
            return;
        }

        solve(i+1,s,temp,ans);
        solve(i+1,s,temp+s[i],ans);
    }
    bool got(string& s, string& t){
        int n = s.size();
        int m = t.size();

        int i = 0, j = 0;
        while(i < n && j < m){
            if(s[i] == t[j]){
                i++; j++;
            }
            else j++;
        }
        return i >= n;
    }
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();

        int maxi = INT_MIN;
        for(int x=0; x<n; x++){
            vector<string> ans;
            solve(0,strs[x],"",ans);

            for(int i=0; i<ans.size(); i++){
                bool f = true;
                for(int j=0; j<n; j++){
                    if(j == x) continue;
                    if(got(ans[i],strs[j])){
                        f = false;
                        break;
                    }
                }
                if(f) maxi = max(maxi,(int)ans[i].size());
            }
        }
        return (maxi == INT_MIN) ? -1 : maxi;
    }
};