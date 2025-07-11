class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(meetings.begin(),meetings.end());

        vector<long long> lastUsed(n,0);
        vector<int> ans(n,0);

        for(int i=0; i<m; i++){
            int start = meetings[i][0];
            int end = meetings[i][1];
            int duration = end - start;
            bool found = false;

            long long earlyEndTime = LLONG_MAX;
            int earlyEndRoom = 0;

            for(int room=0; room<n; room++){
                if(lastUsed[room] <= start){
                    lastUsed[room] = end;
                    ans[room]++;
                    found = true;
                    break;
                }

                if(lastUsed[room] < earlyEndTime){
                    earlyEndTime = lastUsed[room];
                    earlyEndRoom = room;
                }
            }
            if(!found){
                lastUsed[earlyEndRoom] += duration;
                ans[earlyEndRoom]++;
            }
        }

        int maxi = -1, maxUsed = 0;
        for(int i=0; i<n; i++){
            if(ans[i] > maxi){
                maxi = ans[i];
                maxUsed = i;
            }
        }
        return maxUsed;
    }
};