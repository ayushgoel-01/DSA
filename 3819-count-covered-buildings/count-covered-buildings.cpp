class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int size = buildings.size();

        unordered_map<int,pair<int,int>> mp1, mp2;
        for(int i=0; i<n; i++){
            mp1[i] = {INT_MAX,INT_MIN};
            mp2[i] = {INT_MAX,INT_MIN};
        }

        for(auto it: buildings){
            int x = it[0];
            int y = it[1];

            mp1[x].first = min(mp1[x].first,y);
            mp1[x].second = max(mp1[x].second,y);

            mp2[y].first = min(mp2[y].first,x);
            mp2[y].second = max(mp2[y].second,x);
        }

        int ans = 0;
        for(auto it: buildings){
            int x = it[0];
            int y = it[1];

            if(y > mp1[x].first && y < mp1[x].second && x > mp2[y].first && x < mp2[y].second){
                ans++;
            }
        }
        return ans;
    }
};