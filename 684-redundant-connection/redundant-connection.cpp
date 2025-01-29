class Solution {
private:
    bool bfs(int src, int target, unordered_map<int,vector<int>>& mp, int n){
        if(src == target) return true;
        vector<bool> vis(n,false);

        queue<int> q;
        q.push(src);
        vis[src] = true;

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node == target) return true;

            for(auto it: mp[node]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        unordered_map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            if(mp.find(u) != mp.end() && mp.find(v) != mp.end() && bfs(u,v,mp,n)) return edges[i];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        return {};
    }
};