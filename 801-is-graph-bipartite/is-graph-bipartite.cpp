class Solution {
private:
    bool solve(int node, vector<vector<int>>& graph, vector<int>& color, int clr){
        color[node] = clr;

        for(auto it: graph[node]){
            if(color[it] == -1){
                if(!solve(it,graph,color,1-color[node])) return false;
            }
            else if(color[it] == color[node]) return false;
        }
        return true;
    }
public: 
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(!solve(i,graph,color,0)) return false;
            }
        }
        return true;
    }
};