class Solution {
private:
    bool checkBipartite(int curr, vector<int>& colors, unordered_map<int,vector<int>>& mp, int currColor){
        colors[curr] = currColor;

        for(auto it: mp[curr]){
            if(colors[it] == colors[curr]) return false;
            else if(colors[it] == -1){
                colors[it] = 1 - currColor;
                if(!checkBipartite(it,colors,mp,1-currColor)) return false;
            }
        }
        return true;
    }

    int solve(int it, unordered_map<int,vector<int>>& mp, int n){
        queue<int> q;
        q.push(it);

        vector<bool> vis(n+1,false);
        vis[it] = true;

        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            ans++;

            while(size--){
                auto node = q.front();
                q.pop();

                for(auto it: mp[node]){
                    if(!vis[it]){
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
        }
        return ans;
    }

    int findMax(int curr, vector<int>& grps, vector<bool>& vis, unordered_map<int,vector<int>>& mp){
        queue<int> q;
        q.push(curr);

        vis[curr] = true;
        int maxi = grps[curr];

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            maxi = max(maxi,grps[node]);

            for(auto it: mp[node]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        return maxi;
    }

public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mp;
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        vector<int> colors(n+1,-1);
        for(int i=1; i<=n; i++){
            if(colors[i] == -1){
                if(!checkBipartite(i,colors,mp,0)) return -1;
            }
        }

        vector<int> grps(n+1,0);

        for(int i=1; i<=n; i++){            // Calculate maximum groups from every node
            grps[i] = solve(i,mp,n);
        }

        int ans = 0;
        vector<bool> vis2(n+1,false);

        for(int i=1; i<=n; i++){            // Find Maximum grps that can be formed
            if(!vis2[i]) ans += findMax(i,grps,vis2,mp);
        }
        
        return ans;
    }
};