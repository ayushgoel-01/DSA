class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";

        string ans = "";
        vector<string> v;

        while(getline(ss,token,' ')){
            if(!token.empty()){
                v.push_back(token);
            }
        }

        for(int i=v.size()-1; i>=0; i--){
            ans += v[i] + " ";
        }
        ans.pop_back();
        return ans;
    }
};