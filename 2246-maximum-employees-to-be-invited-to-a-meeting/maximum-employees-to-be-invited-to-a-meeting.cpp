class Solution {
private:
    int bfs(int node, unordered_map<int,vector<int>>& adj, vector<bool>& vis){
        queue<pair<int,int>> q;         // {node, Path Length}
        q.push({node,0});
        int maxi = 0;           // Maximum Path Length

        while(!q.empty()){
            auto[currNode,dist] = q.front();
            q.pop();

            for(auto& it: adj[currNode]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push({it,dist+1});
                    maxi = max(maxi,dist+1);
                }
            }
        }
        return maxi;
    }
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int,vector<int>> adj;

        for(int i=0; i<n; i++){
            int u = i;
            int v = favorite[i];
            adj[v].push_back(u);        // Reverse graph to find path length
        }

        int maxCycleLen = 0;
        int happySum = 0;           // Cycle of length 2
        vector<bool> vis(n,false);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                unordered_map<int,int> mp;
                int currNode = i, currCnt = 0;

                while(!vis[currNode]){
                    vis[currNode] = true;
                    mp[currNode] = currCnt;

                    int nextNode = favorite[currNode];
                    currCnt++;

                    if(mp.count(nextNode)){         // Already visited means We got the Cycle
                        int cycleLen = currCnt - mp[nextNode];
                        maxCycleLen = max(maxCycleLen,cycleLen);

                        if(cycleLen == 2){          // Happy Couple Case
                            vector<bool> vis2(n,false);

                            vis2[currNode] = true;
                            vis2[nextNode] = true;
                            // Cycle length of 2 + another paths
                            happySum += 2 + bfs(currNode,adj,vis2) + bfs(nextNode,adj,vis2);
                        }
                        break;
                    }
                    currNode = nextNode;            // We did't got any Cycle
                }
            }
        }
        return max(happySum,maxCycleLen);
    }
};