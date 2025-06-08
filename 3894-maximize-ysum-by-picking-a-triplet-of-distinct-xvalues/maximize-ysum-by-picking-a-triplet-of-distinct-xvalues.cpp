class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();

        map<int,priority_queue<int>> mp;
        for(int i=0; i<n; i++){
            mp[x[i]].push(y[i]);
        }

        priority_queue<int> pq;
        for(auto it: mp){
            pq.push(it.second.top());
        }

        if(pq.size() < 3) return -1;

        int sum = 0, cnt = 3;
        while(!pq.empty() && cnt--){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};