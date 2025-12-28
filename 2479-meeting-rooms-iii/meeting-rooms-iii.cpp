class Solution {
#define ll long long
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(meetings.begin(),meetings.end());

        vector<int> ans(n,0);
        vector<pair<ll,ll>> v(n,{0,0});

        for(int i=0; i<m; i++){
            int currStart = meetings[i][0];
            int currEnd = meetings[i][1];
            int duration = currEnd - currStart;

            bool isFree = false;
            ll earlyStartTime = LLONG_MAX, earlyStartIdx = 0;
            
            for(int j=0; j<n; j++){
                if(v[j].second <= currStart){
                    isFree = true;
                    v[j] = {currStart,currEnd};
                    ans[j]++;
                    break;
                }
                if(v[j].second < earlyStartTime){
                    earlyStartTime = v[j].second;
                    earlyStartIdx = j;
                }
            }

            
            if(!isFree){
                v[earlyStartIdx] = {v[earlyStartIdx].second,v[earlyStartIdx].second + duration};
                ans[earlyStartIdx]++;
            }
        }

        ll maxi = INT_MIN, maxIdx = 0;
        for(int i=0; i<n; i++){
            if(ans[i] > maxi){
                maxi = ans[i];
                maxIdx = i;
            }
        }
        return maxIdx;
    }
};