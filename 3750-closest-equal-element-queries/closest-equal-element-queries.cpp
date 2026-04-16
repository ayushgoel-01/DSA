class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        unordered_map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;
        for(auto it: queries){
            int el = nums[it];
            vector<int>& v = mp[el];
            int size = v.size();

            if(size == 1){
                ans.push_back(-1);
                continue;
            }

            int pos = lower_bound(v.begin(),v.end(),it) - v.begin();
            int res = INT_MAX;
 
            int left = v[((pos-1) + size)%size];
            int d = abs(it-left);
            int cd = n - d;

            res = min({res,d,cd});

            int right = v[(pos+1)%size];
            d = abs(it-right);
            cd = n - d;

            res = min({res,d,cd});

            ans.push_back(res);
        }
        return ans;
    }
};