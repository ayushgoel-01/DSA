class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();

        unordered_map<int,int> mp;
        for(auto i: nums){
            int x = i % value;
            if(x < 0) x = value + x;
            mp[x]++;
        }

        int ans = 0;
        while(true){
            if(mp.find(ans) != mp.end()){
                int cnt = mp[ans];

                int k = 0;
                while(cnt--){
                    mp[ans+(k*value)]++;
                    k++;
                }
                ans++;
            }
            else break;
        }
        return ans;
    }
};