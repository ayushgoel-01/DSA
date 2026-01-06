class Solution {
#define P pair<int,pair<int,int>>
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<P,vector<P>,greater<P>> pq;
        vector<vector<int>> dis(n, vector<int>(m,1e9));
        pq.push({0,{0,0}});
        dis[0][0] = 0;

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        while(!pq.empty()){
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == n-1 && col == m-1) return diff;

            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    int newDiff = max(diff,abs(heights[nrow][ncol] - heights[row][col]));

                    if(newDiff < dis[nrow][ncol]){
                        pq.push({newDiff,{nrow,ncol}});
                        dis[nrow][ncol] = newDiff;
                    }
                }
            }
        }
        return -1;
    }
};