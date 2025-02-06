class Solution {            // Better Approach
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=n-1; j>i; j--){
                long long prod = nums[i] * nums[j];
                unordered_set<int> st;

                for(int k=i+1; k<j; k++){
                    if(prod % nums[k] == 0){
                        int val = prod / nums[k];

                        if(st.count(val) >= 1) ans++;
                        st.insert(nums[k]);
                    }
                }
            }
        }
        return ans * 8;         // Every tuple can have 8 permutations
    }
};






// class Solution {            // Brute Force
// public:
//     int tupleSameProduct(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(),nums.end());

//         int ans = 0;
//         for(int i=0; i<n; i++){
//             for(int j=n-1; j>i; j--){
//                 if(i == j) continue;

//                 int k = i+1, l = j-1;
//                 if(i == k || j == k) k++;
//                 if(i == l || j == l) l--;

//                 while(k < l){
//                     long long a = nums[i] * nums[j];
//                     long long b = nums[k] * nums[l];

//                     if(a == b){
//                         ans++;
//                         k++;
//                     }
//                     else if(a > b) k++;
//                     else l--;
//                 }
//             }
//         }
//         return ans * 8;         // Every tuple can have 8 permutations
//     }
// };