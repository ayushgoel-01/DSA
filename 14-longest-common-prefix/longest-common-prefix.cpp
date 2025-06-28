class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        sort(strs.begin(),strs.end());

        string ans = "";
        string temp = strs[0];

        for(int i=0; i<temp.size(); i++){
            bool f = true;
            for(int j=1; j<n; j++){
                if(strs[j][i] != temp[i]){
                    f = false;
                    break;
                }
            }
            if(f) ans += temp[i];
            else break;
        }
        return ans;
    }
};