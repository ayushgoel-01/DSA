class Solution {
private:
    bool bfs(int src, int target, unordered_map<int,vector<int>>& mp, int n){
        vector<bool> vis(n,false);
        vis[src] = true;

        queue<int> q;
        q.push(src);
        while(!q.empty()){
            auto node = q.front();
            q.pop();

            for(auto it: mp[node]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push(it);
                    if(it == target) return true;
                }
            }
        }
        return false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        int m = queries.size();

        unordered_map<int,vector<int>> mp;
        for(auto it: prerequisites){
            int u = it[0];
            int v = it[1];
            mp[u].push_back(v);
        }

        vector<bool> ans(m,false);
        for(int i=0; i<m; i++){
            int u = queries[i][0];
            int v = queries[i][1];
            
            if(bfs(u,v,mp,n)) ans[i] = true;
        }
        return ans;
    }
};