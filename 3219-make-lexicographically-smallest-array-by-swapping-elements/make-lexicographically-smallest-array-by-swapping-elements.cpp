class Solution {            // Using Doubly Linked List
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> v(nums.begin(),nums.end());
        sort(v.begin(),v.end());

        unordered_map<int,list<int>> mp;       // Grp -> element mapping , O(1) using DLL
        unordered_map<int,int> elToGrp;         // element -> Grp mapping

        int grp = 1;
        mp[grp].push_back(v[0]);
        elToGrp[v[0]] = grp;

        for(int i=1; i<n; i++){
            if(v[i] - v[i-1] > limit){          // Change thr group
                grp++;
            }
            mp[grp].push_back(v[i]);
            elToGrp[v[i]] = grp;
        }

        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            int el = nums[i];
            int grp = elToGrp[el];

            int val = *mp[grp].begin();          // Find Smallest element of that group
            mp[grp].pop_front();
            ans[i] = val;
        }
        return ans;
    }
};




// class Solution {            // Using Queue
// public:
//     vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
//         int n = nums.size();
//         vector<int> v(nums.begin(),nums.end());
//         sort(v.begin(),v.end());

//         unordered_map<int,queue<int>> mp;       // Grp -> element mapping
//         unordered_map<int,int> elToGrp;         // element -> Grp mapping

//         int grp = 1;
//         mp[grp].push(v[0]);
//         elToGrp[v[0]] = grp;

//         for(int i=1; i<n; i++){
//             if(v[i] - v[i-1] > limit){          // Change thr group
//                 grp++;
//             }
//             mp[grp].push(v[i]);
//             elToGrp[v[i]] = grp;
//         }

//         vector<int> ans(n,0);
//         for(int i=0; i<n; i++){
//             int el = nums[i];
//             int grp = elToGrp[el];

//             int val = mp[grp].front();          // Find Smallest element of that group
//             mp[grp].pop();
//             ans[i] = val;
//         }
//         return ans;
//     }
// };