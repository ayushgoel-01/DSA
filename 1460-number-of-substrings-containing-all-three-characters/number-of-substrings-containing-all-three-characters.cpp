class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0, j = 0, ans = 0;
        vector<int> v(3,0);

        while(j < n){
            v[s[j] - 'a']++;
            while(i <= j && v[0] >= 1 && v[1] >= 1 && v[2] >= 1){
                ans += n-j;
                v[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};