class Solution {
private:
    void bfs(int node, vector<int>& vis, vector<int> adj[]){
        vis[node] = 1;

        queue<int> q;
        q.push(node);

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            for(auto it: adj[curr]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n,0);

        int ans = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                bfs(i,vis,adj);
            }
        }
        return ans;
    }
};