class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int m = startTime.size();
        vector<int> free;

        free.push_back(startTime[0]);

        for(int i=1; i<m; i++){
            free.push_back(startTime[i] - endTime[i-1]);
        }

        free.push_back(eventTime - endTime[m-1]);

        int n = free.size();
        vector<int> leftMax(n,0), rightMax(n,0);

        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1],free[i+1]);
        }
        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1],free[i-1]);
        }

        int ans = 0;
        for(int i=1; i<n; i++){
            int d = endTime[i-1] - startTime[i-1];

            // case 1
            if(d <= max(leftMax[i-1],rightMax[i])){
                ans = max(ans,free[i-1] + d + free[i]);
            }

            // case 2
            ans = max(ans,free[i-1] + free[i]);
        }
        return ans;
    }
};