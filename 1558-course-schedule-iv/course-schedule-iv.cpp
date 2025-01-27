class Solution {            // Approach - 2 Using Topological sorting (Kahn's algo)
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        int m = queries.size();

        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0);

        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        unordered_map<int,unordered_set<int>> mp;
        while(!q.empty()){
            auto node = q.front();
            q.pop();

            for(auto& it: adj[node]){
                mp[it].insert(node);
                // Find nodes that make transitive dependency
                for(auto& val: mp[node]){
                    mp[it].insert(val);
                }

                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        vector<bool> ans(m,false);
        for(int i=0; i<m; i++){
            int u = queries[i][0];
            int v = queries[i][1];

            if(mp[v].count(u) >= 1) ans[i] = true;
        }
        return ans;
    }
};




// class Solution {            // Approach - 1 using BFS
// private:
//     bool bfs(int src, int target, unordered_map<int,vector<int>>& mp, int n){
//         vector<bool> vis(n,false);
//         vis[src] = true;

//         queue<int> q;
//         q.push(src);
//         while(!q.empty()){
//             auto node = q.front();
//             q.pop();

//             for(auto it: mp[node]){
//                 if(!vis[it]){
//                     vis[it] = true;
//                     q.push(it);
//                     if(it == target) return true;
//                 }
//             }
//         }
//         return false;
//     }
// public:
//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         int n = numCourses;
//         int m = queries.size();

//         unordered_map<int,vector<int>> mp;
//         for(auto it: prerequisites){
//             int u = it[0];
//             int v = it[1];
//             mp[u].push_back(v);
//         }

//         vector<bool> ans(m,false);
//         for(int i=0; i<m; i++){
//             int u = queries[i][0];
//             int v = queries[i][1];
            
//             if(bfs(u,v,mp,n)) ans[i] = true;
//         }
//         return ans;
//     }
// };