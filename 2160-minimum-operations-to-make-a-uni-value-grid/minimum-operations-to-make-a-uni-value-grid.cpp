class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> v;
        for(auto i: grid){
            for(auto j: i) v.push_back(j);
        }
        sort(v.begin(),v.end());

        int size = n*m;

        int target = v[size/2];
        int ans = 0;
        for(int i=0; i<size; i++){
            if(abs(v[i]-target) % x != 0) return -1;
            ans += abs(v[i] - target)/x;
        }
        return ans;
    }
};