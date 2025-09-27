class Solution {            // Using Shoelace formula
private:
    double solve(vector<int>& a, vector<int>& b, vector<int>& c){
        int x1 = a[0], y1 = a[1];
        int x2 = b[0], y2 = b[1];
        int x3 = c[0], y3 = c[1];

        return 0.5 * abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();

        double ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    double val = solve(points[i],points[j],points[k]);
                    ans = max(ans,val);
                }
            }
        }
        return ans;
    }
};