class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        long long ans = 0;
        int cnt = 0, mini = INT_MAX;
        bool neg = false;
        long long sum = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] < 0){
                    neg = true;
                    cnt++;
                }
                mini = min(mini,abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        }

        if(neg && cnt % 2 == 1){
            sum -= 2 * mini;
        }
        return sum;
    }
};