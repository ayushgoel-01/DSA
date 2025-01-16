class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int ans = 0;
        if(m % 2 == 1){
            for(auto i: nums1) ans = ans ^ i;
        }

        if(n % 2 == 1){
            for(auto i: nums2) ans = ans ^ i;
        }
        return ans;
    }
};




// class Solution {         // Using Map
// #define ll long long
// public:
//     int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         int m = nums2.size();

//         unordered_map<ll,ll> mp;

//         for(auto i: nums1) mp[i] += m;
//         for(auto i: nums2) mp[i] += n;

//         int ans = 0;
//         for(auto it: mp){
//             if(it.second % 2 == 1) ans = ans ^ it.first;
//         }
//         return ans;
//     }
// };