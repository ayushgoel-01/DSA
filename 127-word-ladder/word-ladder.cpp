class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            string s = q.front().first;
            int val = q.front().second;
            q.pop();

            if(s == endWord) return val;

            for(int i=0; i<s.size(); i++){
                char original = s[i];
                for(char ch='a'; ch<='z'; ch++){
                    s[i] = ch;

                    if(st.count(s) >= 1){
                        st.erase(s);
                        q.push({s,val+1});
                    }
                }
                s[i] = original;
            }
        }
        return 0;
    }
};