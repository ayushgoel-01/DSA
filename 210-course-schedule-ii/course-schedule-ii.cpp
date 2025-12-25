class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<int> adj[n];
        vector<int> inn(n,0);
        for(auto it: prerequisites){
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
            inn[v]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(inn[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adj[node]){
                inn[it]--;
                if(inn[it] <= 0) q.push(it);
            }
        }
        if(ans.size() != n) return {};
        return ans;
    }
};