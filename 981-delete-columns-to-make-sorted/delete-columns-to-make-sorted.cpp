class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        vector<int> v(m,0);
        for(int i=1; i<n; i++){
            string s1 = strs[i-1];
            string s2 = strs[i];

            for(int j=0; j<m; j++){
                if(s1[j] > s2[j]){
                    v[j] = 1;
                }
            }
        }
        return accumulate(v.begin(),v.end(),0);
    }
};