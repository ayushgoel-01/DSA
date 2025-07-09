class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> v;
        if(startTime[0] > 0) v.push_back(startTime[0]);
        for(int i=1; i<n; i++){
            v.push_back(startTime[i] - endTime[i-1]);
        }

        if(endTime[n-1] < eventTime) v.push_back(eventTime - endTime[n-1]);

        int i = 0, j = 0;
        int sum = 0, maxi = 0;
        while(j < v.size()){
            sum += v[j];
            while(j-i+1 > k+1){
                sum -= v[i];
                i++;
            }
            maxi = max(maxi,sum);
            j++;
        }
        return maxi;
    }
};