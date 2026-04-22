class Solution {
private:
    bool solve(string& s1, string& s2){
        int n = s1.size();
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]) cnt++;
            if(cnt > 2) return false;
        }
        return cnt <= 2;
    }
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for(auto s1: queries){
            for(auto s2: dictionary){
                if(solve(s1,s2)){
                    ans.push_back(s1);
                    break;
                }
            }
        }
        return ans;
    }
};