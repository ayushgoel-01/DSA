class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();

        unordered_map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[labels[i]].push_back(values[i]);
        }

        priority_queue<pair<int,int>> pq;
        for(auto it: mp){
            for(auto j: it.second) pq.push({j,it.first});
        }

        unordered_map<int,int> lmt;
        int ans = 0;

        while(!pq.empty() && numWanted > 0){
            int val = pq.top().first;
            int label = pq.top().second;
            pq.pop();

            if(lmt[label] < useLimit){
                ans += val;
                lmt[label]++;
                numWanted--;
            }
        }
        return ans;
    }
};