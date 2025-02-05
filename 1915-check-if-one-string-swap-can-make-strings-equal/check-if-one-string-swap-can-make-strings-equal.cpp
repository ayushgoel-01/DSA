class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        int n = s1.size();

        int cnt = 0;
        vector<char> v;

        for(int i=0; i<n; i++){
            if(s1[i] == s2[i]){
                cnt++;
                continue;
            }
            else{
                v.push_back(s1[i]);
                v.push_back(s2[i]);
            }
        }
        
        if(cnt < n-2 || v.size() != 4) return false;

        return v[0] == v[3] && v[1] == v[2];
    }
};