class Solution {
unordered_map<string,int> mp;
vector<vector<string>> ans;
private:
    void solve(string s, vector<string>& seq, string beginWord){
        if(s == beginWord){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }

        int steps = mp[s];

        for(int i=0; i<s.size(); i++){
            char original = s[i];
            for(char ch='a'; ch<='z'; ch++){
                s[i] = ch;

                if(mp.find(s) != mp.end() && mp[s] + 1 == steps){
                    seq.push_back(s);
                    solve(s,seq,beginWord);
                    seq.pop_back();
                }
            }
            s[i] = original;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());

        queue<string> q;
        q.push(beginWord);

        mp[beginWord] = 1;
        int size = beginWord.size();
        st.erase(beginWord);

        while(!q.empty()){
            string s = q.front();
            q.pop();
            int steps = mp[s];

            if(s == endWord) break;

            for(int i=0; i<size; i++){
                char original = s[i];
                for(char ch='a'; ch<='z'; ch++){
                    s[i] = ch;

                    if(st.count(s) >= 1){
                        q.push(s);
                        st.erase(s);
                        mp[s] = steps + 1;
                    }
                }
                s[i] = original;
            }
        }

        if(mp.find(endWord) != mp.end()){
            vector<string> v;
            v.push_back(endWord);
            solve(endWord,v,beginWord);
        }
        return ans;
    }
};