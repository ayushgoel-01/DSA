class Solution {
private:
    bool dfs(int curr, vector<vector<int>>& adj, vector<int>& color, int currColor){
        color[curr] = currColor;

        for(auto it: adj[curr]){
            if(color[it] == color[curr]) return false;
            else if(color[it] == -1){
                color[it] = 1 - currColor;

                if(!dfs(it,adj,color,1-currColor)) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n,-1);
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(!dfs(i,graph,color,0)) return false;
            }
        }
        return true;
    }
};