class Solution {
private:
    bool solve(vector<vector<int>>& squares, double mid, double totalArea){
        double bottomArea = 0;

        for(auto &it: squares){
            double x = it[0];
            double y = it[1];
            double l = it[2];

            double bottomY = y;
            double topY = y + l;

            if(mid >= topY){
                bottomArea += (l * l);
            }
            else if(mid > bottomY){
                bottomArea += (mid - bottomY) * l;
            }
        }
        return bottomArea >= totalArea/2.0;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();

        double start = INT_MAX;
        double end = INT_MIN;
        double totalArea = 0.00000;

        for(auto &it: squares){
            double x = it[0];
            double y = it[1];
            double l = it[2];

            totalArea += l * l;
            start = min(start,y);
            end = max(end,y+l);
        }

        double ans = 0.00000;
        while(end - start > 1e-5){
            double mid = start + (end - start)/2;

            ans = mid;

            if(solve(squares,mid,totalArea)){           // BottomArea is greater
                end = mid;
            }
            else start = mid;
        }
        return ans;
    }
};