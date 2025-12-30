class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());

        queue<pair<string,int>> q;
        q.push({beginWord,0});
        unordered_set<string> vis;

        while(!q.empty()){
            string s = q.front().first;
            int val = q.front().second;
            q.pop();

            if(s == endWord) return val + 1;

            for(int i=0; i<s.size(); i++){
                for(char ch='a'; ch<='z'; ch++){
                    string temp = s;
                    temp[i] = ch;

                    if(st.count(temp) >= 1 && vis.count(temp) <= 0){
                        q.push({temp,val+1});
                        vis.insert(temp);
                    }
                }
            }
        }
        return 0;
    }
};