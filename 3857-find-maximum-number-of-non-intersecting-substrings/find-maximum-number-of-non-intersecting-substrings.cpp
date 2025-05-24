class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();

        int ans = 0, pi = -1;
        unordered_map<char,int> mp;

        for(int i=0; i<n; i++){
            if(mp.find(word[i]) != mp.end()){
                if(abs(i - mp[word[i]]) >= 3 && mp[word[i]] > pi){
                    pi = i;
                    ans++;
                    mp.clear();
                }
            }
            else{
                mp[word[i]] = i;
            }
        }
        return ans;
    }
};