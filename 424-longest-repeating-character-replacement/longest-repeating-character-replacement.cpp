class Solution {
private:
    int solve(string& s, int k, char ch){
        int n = s.size();
        int i = 0, j = 0, ans = 0;
        while(j < n){
            if(s[j] != ch) k--;
            while(i <= j && k < 0){
                if(s[i] != ch) k++;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int ans = 0;
        for(char ch='A'; ch<='Z'; ch++){
            ans = max(ans,solve(s,k,ch));
        }
        return ans;
    }
};