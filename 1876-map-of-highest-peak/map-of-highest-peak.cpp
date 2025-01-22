class Solution {
#define P pair<int,pair<int,int>>
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> ans(n, vector<int>(m,1e9));
        priority_queue<P,vector<P>,greater<P>> pq;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j] == 1){
                    pq.push({0,{i,j}});
                    ans[i][j] = 0;
                }
            }
        }

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int currD = top.first;
            int row = top.second.first;
            int col = top.second.second;

            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    if(currD + 1 < ans[nrow][ncol]){
                        ans[nrow][ncol] = currD + 1;
                        pq.push({currD+1,{nrow,ncol}});
                    }
                }
            }
        }
        return ans;
    }
};