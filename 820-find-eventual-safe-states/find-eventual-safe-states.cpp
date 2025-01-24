class Solution {            // DFS
private:
    bool detectCycle(int node, vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& inRecursion){
        vis[node] = true;
        inRecursion[node] = true;

        // Check for Cycle
        for(auto& curr: graph[node]){
            if(!vis[curr] && detectCycle(curr,graph,vis,inRecursion)) return true;
            else if(inRecursion[curr] == true) return true;
        }

        inRecursion[node] = false;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool> vis(n,false), inRecursion(n,false);

        for(int i=0; i<n; i++){
            if(!vis[i]) detectCycle(i,graph,vis,inRecursion);
        }

        vector<int> ans;
        for(int i=0; i<n; i++){         // Nodes which are not part of Cycle
            if(!inRecursion[i]) ans.push_back(i);
        }
        return ans;
    }
};