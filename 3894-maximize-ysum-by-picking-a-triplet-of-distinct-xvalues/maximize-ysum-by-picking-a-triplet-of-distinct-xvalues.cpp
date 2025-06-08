class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();

        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[x[i]] = max(mp[x[i]],y[i]);
        }

        priority_queue<int> pq;
        for(auto& it: mp){
            pq.push(it.second);
        }

        if(pq.size() < 3) return -1;

        int sum = 0;
        for(int i=0; i<3; i++){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};