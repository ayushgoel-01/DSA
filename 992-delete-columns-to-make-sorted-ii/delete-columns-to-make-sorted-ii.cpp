class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        int ans = 0;
        vector<bool> v(n,false);

        for(int i=0; i<m; i++){
            bool deleted = false;
            for(int j=0; j<n-1; j++){
                if(!v[j] && strs[j][i] > strs[j+1][i]){
                    deleted = true;
                    ans++;
                    break;
                }
            }
            if(deleted) continue;

            for(int j=0; j<n-1; j++){
                v[j] = v[j] || strs[j][i] < strs[j+1][i];
            }
        }
        return ans;
    }
};