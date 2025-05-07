class Solution {
#define P pair<int,pair<int,int>>
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,{0,0}});

        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> dist(n, vector<int>(m,1e9));
        dist[0][0] = 0;

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int t = top.first;
            int row = top.second.first;
            int col = top.second.second;

            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;

                    if(1 + t > moveTime[nrow][ncol]){
                        pq.push({1+t,{nrow,ncol}});
                        dist[nrow][ncol] = 1 + t;
                    }
                    else{
                        pq.push({moveTime[nrow][ncol]+1,{nrow,ncol}});
                        dist[nrow][ncol] = moveTime[nrow][ncol] + 1;
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};