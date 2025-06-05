class Solution {
private:
    char dfs(char ch, vector<bool>& vis, unordered_map<char,vector<char>>& adj){
        vis[ch-'a'] = true;

        char ans = ch;
        for(auto it: adj[ch]){
            if(!vis[it-'a']){
                ans = min(ans,dfs(it,vis,adj));
            }
        }
        return ans;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();

        unordered_map<char,vector<char>> adj;
        for(int i=0; i<n; i++){
            char a = s1[i];
            char b = s2[i];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        string ans = "";

        for(int i=0; i<baseStr.size(); i++){
            char ch = baseStr[i];
            vector<bool> vis(26,false);

            char mini = dfs(ch,vis,adj);
            ans += mini;
        }
        return ans;
    }
};