class Solution {
private:
    void dfs(int node, int parent, int& timer, unordered_map<int,vector<int>>& adj, vector<int>& xorr, vector<int>& inTime, vector<int>& outTime, vector<int>& nums){
        xorr[node] = nums[node];
        inTime[node] = timer;
        timer++;

        for(auto& it: adj[node]){
            if(it != parent){
                dfs(it,node,timer,adj,xorr,inTime,outTime,nums);
                xorr[node] ^= xorr[it];
            }
        }

        outTime[node] = timer;
        timer++;
    }

    bool isAncestor(int u, int v, vector<int>& inTime, vector<int>& outTime){
        return inTime[u] <= inTime[v] && outTime[v] <= outTime[u];
    }

    int findScore(int a, int b, int c){
        return max({a,b,c}) - min({a,b,c});
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        unordered_map<int,vector<int>> adj;
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> xorr(n,0), inTime(n,0), outTime(n,0);
        int timer = 0;

        dfs(0,-1,timer,adj,xorr,inTime,outTime,nums);

        int ans = INT_MAX;
        for(int u=1; u<n; u++){
            for(int v=u+1; v<n; v++){
                int xor1, xor2, xor3;

                if(isAncestor(u,v,inTime,outTime)){
                    xor1 = xorr[v];
                    xor2 = xorr[u] ^ xor1;
                    xor3 = xorr[0] ^ xor1 ^ xor2;
                }
                else if(isAncestor(v,u,inTime,outTime)){
                    xor1 = xorr[u];
                    xor2 = xorr[v] ^ xor1;
                    xor3 = xorr[0] ^ xor1 ^ xor2;
                }
                else{
                    xor1 = xorr[u];
                    xor2 = xorr[v];
                    xor3 = xorr[0] ^ xor1 ^ xor2;
                }

                ans = min(ans,findScore(xor1,xor2,xor3));
            }
        }
        return ans;
    }
};