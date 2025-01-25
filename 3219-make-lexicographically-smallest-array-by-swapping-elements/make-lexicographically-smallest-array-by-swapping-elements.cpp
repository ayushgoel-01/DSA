class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> v(nums.begin(),nums.end());
        sort(v.begin(),v.end());

        unordered_map<int,queue<int>> mp;
        unordered_map<int,int> elToGrp;

        int grp = 1;
        mp[grp].push(v[0]);
        elToGrp[v[0]] = grp;

        for(int i=1; i<n; i++){
            if(v[i] - v[i-1] > limit){
                grp++;
            }
            mp[grp].push(v[i]);
            elToGrp[v[i]] = grp;
        }

        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            int el = nums[i];
            int grp = elToGrp[el];

            int val = mp[grp].front();
            mp[grp].pop();
            ans[i] = val;
        }
        return ans;
    }
};