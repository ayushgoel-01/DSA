class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0, diagonal = 0;
        for(auto it: dimensions){
            int l = it[0];
            int w = it[1];

            int d = (l*l) + (w*w);
            if(d > diagonal){
                diagonal = d;
                ans = l * w;
            }
            else if(d == diagonal){
                ans = max(ans,l*w);
            }
        }
        return ans;
    }
};