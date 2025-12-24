class Solution {
private:
    bool solve(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& pathVis,
    vector<bool>& check){
        vis[node] = true;
        pathVis[node] = true;

        for(auto it: adj[node]){
            if(!vis[it]){
                if(solve(it,adj,vis,pathVis,check)){
                    check[node] = false;
                    return true;
                }
            }
            else if(pathVis[it]){
                check[node] = false;
                return true;
            }
        }

        pathVis[node] = false;
        check[node] = true;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool> vis(n,false), pathVis(n,false), check(n,false);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                solve(i,graph,vis,pathVis,check);
            }
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(check[i]) ans.push_back(i);
        }
        return ans;
    }
};