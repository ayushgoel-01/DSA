class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;
        for(auto i: nums) mp[i]++;

        vector<pair<int,int>> v;
        for(auto it: mp){
            v.push_back({it.first,it.second});
        }

        sort(v.rbegin(),v.rend());
        unordered_map<int,int> mp2;
        
        int sum = 0;
        for(auto it: v){
            int el = it.first;
            int freq = it.second;

            if(sum + freq <= k){
                sum += freq;
                mp2[el] = freq;
            }
            else{
                int newF = k-sum;
                if(newF > 0){
                    mp2[el] = newF;
                }
                break;
            }
        }

        vector<int> ans;
        for(auto i: nums){
            if(mp2.find(i) != mp2.end()){
                ans.push_back(i);
                mp2[i]--;

                if(mp2[i] <= 0) mp2.erase(i);
            }
        }
        return ans;
    }
};