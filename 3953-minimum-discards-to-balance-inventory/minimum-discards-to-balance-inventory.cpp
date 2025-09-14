class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n = arrivals.size();

        int ans = 0, j = 0;
        unordered_map<int,int> mp;
        while(j < n){
            if(mp[arrivals[j]] == m){
                ans++;
                arrivals[j] = -1;
            }
            else{
                mp[arrivals[j]]++;
            }
            
            if(j-w+1 >= 0 && arrivals[j-w+1] != -1){
                mp[arrivals[j-w+1]]--;
            }
            j++;
        }
        return ans;
    }
};