class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        // Sort events based on starting day
        sort(events.begin(),events.end());

        int ans = 0, day = events[0][0];
        int i = 0;
        priority_queue<int,vector<int>,greater<int>> pq;

        while(!pq.empty() || i < n){
            while(i < n && events[i][0] == day){
                pq.push(events[i][1]);          // Push ending day in min Heap
                i++;
            }

            if(!pq.empty()){            // Process less ending day first
                pq.pop();
                ans++;
            }
            day++;

            while(!pq.empty() && pq.top() < day){
                pq.pop();
            }
        }
        return ans;
    }
};