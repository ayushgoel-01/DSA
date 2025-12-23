class Solution {
private:
    bool solve(int node, vector<vector<int>>& graph, vector<int>& color){
        queue<int> q;
        q.push(node);
        color[node] = 0;

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            for(auto it: graph[top]){
                if(color[it] == -1){
                    color[it] = 1 - color[top]; 
                    q.push(it);
                }
                else if(color[it] == color[top]) return false;
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
                if(!solve(i,graph,color)) return false;
            }
        }
        return true;
    }
};