class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        int mini = INT_MAX;

        unordered_map<int,int> mp;
        for(auto i: basket1){
            mp[i]++;
            mini = min(mini,i);
        }
        for(auto i: basket2){
            mp[i]--;
            mini = min(mini,i);
        }

        vector<int> v;
        for(auto it: mp){
            int el = it.first;
            int cnt = it.second;

            if(cnt == 0) continue;
            if(cnt % 2 == 1) return -1;
            
            for(int i=1; i<=abs(cnt)/2; i++){
                v.push_back(el);
            }
        }

        sort(v.begin(),v.end());
        long long ans = 0;
        for(int i=0; i<v.size()/2; i++){
            ans = ans + min(v[i],2*mini);
        }
        return ans;
    }
};