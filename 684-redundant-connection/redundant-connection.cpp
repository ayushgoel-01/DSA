class DSU{
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1);

        for(int i=1; i<=n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x){        // Return parent of node x & do Path Compression
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);         // Path Compression
    }

    void Union(int x, int y){           // Union 2 nodes
        int xParent = find(x);
        int yParent = find(y);

        if(xParent == yParent) return;

        if(rank[xParent] > rank[yParent]){          // Make X parent of Y
            parent[yParent] = xParent;
        }
        else if(rank[xParent] < rank[yParent]){     // Make Y parent of X
            parent[xParent] = yParent;
        }
        else{
            parent[yParent] = xParent;              // Kisi ko bhi bna do & update the rank
            rank[xParent]++;                        
        }
    }
};

class Solution {            // Using DSU
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DSU dsu(n);         // Crete Object

        for(auto& it: edges){
            int u = it[0];
            int v = it[1];

            if(dsu.find(u) == dsu.find(v)){         // Parents of both nodes are Same
                return it;
            }

            dsu.Union(u,v);         // Merge two nodes
        }
        return {};
    }
};




// class Solution {            // Using BFS
// private:
//     bool bfs(int src, int target, unordered_map<int,vector<int>>& mp, int n){
//         if(src == target) return true;
//         vector<bool> vis(n,false);

//         queue<int> q;
//         q.push(src);
//         vis[src] = true;

//         while(!q.empty()){
//             auto node = q.front();
//             q.pop();
//             if(node == target) return true;

//             for(auto it: mp[node]){
//                 if(!vis[it]){
//                     vis[it] = true;
//                     q.push(it);
//                 }
//             }
//         }
//         return false;
//     }
// public:
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         int n = edges.size();

//         unordered_map<int,vector<int>> mp;
//         for(int i=0; i<n; i++){
//             int u = edges[i][0];
//             int v = edges[i][1];

// // Check if both nodes are present in graph and both are connected, then we can remove that edge
//             if(mp.find(u) != mp.end() && mp.find(v) != mp.end() && bfs(u,v,mp,n)){
//                 return edges[i];
//             }

//             mp[u].push_back(v);
//             mp[v].push_back(u);
//         }
//         return {};
//     }
// };