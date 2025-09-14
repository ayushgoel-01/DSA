class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || 
                ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    string toLowerCase(string& s){
        int n = s.size();
        string ans = "";

        for(auto i: s){
            if(i >= 'a' && i <= 'z') ans += i;
            else ans += i - 'A' + 'a';
        }
        return ans;
    }

    string toWildCard(string& s){
        string tmp = toLowerCase(s);
        string ans = "";

        for(auto i: tmp){
            if(isVowel(i)) ans += "*";
            else ans += i;
        }
        return ans;
    }

    void makeMapping(vector<string>& v, int n, unordered_map<string,string>& mp1,
        unordered_map<string,string>& mp2){
        for(int i=0; i<n; i++){
            string s = v[i];
            string temp = toLowerCase(s);
            if(mp1.find(temp) == mp1.end()) mp1[temp] = s;
        }

        for(int i=0; i<n; i++){
            string s = v[i];
            string temp = toWildCard(s);
            if(mp2.find(temp) == mp2.end()) mp2[temp] = s;
        }
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n = wordlist.size();
        int m = queries.size();

        unordered_map<string,string> mp1, mp2;
        unordered_set<string> st(wordlist.begin(),wordlist.end());

        makeMapping(wordlist,n,mp1,mp2);
        vector<string> ans(m,"");
        
        for(int i=0; i<m; i++){
            string l1 = toLowerCase(queries[i]);
            string l2 = toWildCard(queries[i]);

            if(st.count(queries[i]) >= 1) ans[i] = queries[i];
            else if(mp1.find(l1) != mp1.end()) ans[i] = mp1[l1];
            else if(mp2.find(l2) != mp2.end()) ans[i] = mp2[l2];
        }
        return ans;
    }
};