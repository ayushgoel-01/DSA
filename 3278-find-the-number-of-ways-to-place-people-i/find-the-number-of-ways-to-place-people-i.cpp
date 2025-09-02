class Solution {
private:
    bool solve(int x1, int y1, int x2, int y2, unordered_set<int>& st1, unordered_set<int>& st2){
        bool f1 = true, f2 = true;
        for(int i=x1; i<=x2; i++){
            if(st1.count(i) >= 1){
                f1 = false;
                break;
            }
        }
        for(int j=y2; j<=y1; j++){
            if(st2.count(j) >= 1){
                f2 = false;
                break;
            }
        }
        return f1 || f2;
    }
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        auto cmp = [&](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        };
        sort(points.begin(),points.end(),cmp);

        int ans = 0;

        for(int i=0; i<n; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            unordered_set<int> st1, st2;
            for(int j=i+1; j<n; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(x1 <= x2 && y1 >= y2 && solve(x1,y1,x2,y2,st1,st2)) ans++;
                st1.insert(x2);
                st2.insert(y2);
            }
        }
        return ans;
    }
};