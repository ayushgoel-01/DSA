class Solution {
private:
    bool match(string a, string b){
        int n = a.size(), m = b.size();

        if(n < m) return false;
        int i = 0, j = 0;
        while(i < n && j < m){
            if(a[i] != b[j]) return false;
            i++; j++;
        }
        if(j == m && a[i] != '/') return false;
        return true;
    }
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(),folder.end());

        vector<string> ans;
        string s = folder[0];
        ans.push_back(s);

        for(int i=1; i<n; i++){
            if(!match(folder[i],s)){
                ans.push_back(folder[i]);
                s = folder[i];
            }
        }
        return ans;
    }
};