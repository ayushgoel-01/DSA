class Solution {
private:
    bool solve(int source, int target, int threshold, int k, vector<pair<int,int>> adj[], int n){

        deque<int> dq;
        dq.push_back(source);

        vector<int> dist(n,1e9);
        dist[source] = 0;

        while(!dq.empty()){
            auto node = dq.front();
            dq.pop_front();

            for(auto it: adj[node]){
                int adjNode = it.first;
                int cost = (it.second > threshold) ? 1 : 0;

                if(dist[node] + cost < dist[adjNode]){
                    dist[adjNode] = dist[node] + cost;

                    if(cost == 0) dq.push_front(adjNode);
                    else dq.push_back(adjNode);
                }
            }
        }
        return dist[target] <= k;
    }
public:
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        if(source == target) return 0;

        vector<pair<int,int>> adj[n];
        int start = 0, end = 0;
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            end = max(end,w);

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        if(!solve(source,target,end,k,adj,n)) return -1;

        int ans = -1;
        while(start <= end){
            int mid = start + (end-start)/2;

            if(solve(source,target,mid,k,adj,n)){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};