class Solution {
private:
    void dfs(int idx, vector<vector<int>>& stones, vector<bool>& vis){
        int n = stones.size();
        vis[idx] = true;

        for(int i=0; i<n; i++){
            int r = stones[i][0];
            int c = stones[i][1];

            if(!vis[i] && (stones[idx][0] == r || stones[idx][1] == c)){
                dfs(i,stones,vis);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> vis(n,false);

        int groups = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i,stones,vis);
                groups++;
            }
        }
        return n - groups;
    }
};