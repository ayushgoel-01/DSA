class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' ||
                ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
public:
    string sortVowels(string s) {
        int n = s.size();

        string v = "";
        for(int i=0; i<n; i++){
            if(isVowel(s[i])){
                v += s[i];
            }
        }

        sort(v.begin(),v.end());
        string ans = "";
        int idx = 0;
        for(int i=0; i<n; i++){
            if(isVowel(s[i])){
                ans += v[idx++];
            }
            else ans += s[i];
        }
        return ans;
    }
};