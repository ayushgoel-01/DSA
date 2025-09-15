class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st;
        for(auto i: brokenLetters) st.insert(i);

        int ans = 0;
        bool got = false;
        for(auto i: text){
            if(st.count(i) >= 1) got = true;
            else{
                if(i == ' ' && !got) ans++;
                else if(i == ' ') got = false;
            }
        }
        if(!got) ans++;
        return ans;
    }
};