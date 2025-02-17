class Solution {
int n;
private:
    void solve(string& tiles, vector<bool>& used, unordered_set<string>& st, string& curr){
        st.insert(curr);

        for(int i=0; i<n; i++){
            if(used[i]) continue;

            used[i] = true;
            curr.push_back(tiles[i]);

            solve(tiles,used,st,curr);

            used[i] = false;
            curr.pop_back();
        }
    }
public:
    int numTilePossibilities(string tiles) {
        n = tiles.size();

        vector<bool> used(n,false);
        unordered_set<string> st;
        string curr = "";

        solve(tiles,used,st,curr);
        return st.size() - 1;          // Remove empty string
    }
};