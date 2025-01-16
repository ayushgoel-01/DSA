class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        vector<int> v(n);
        v[0] = 0;
        for(int i=1; i<n; i++){
            v[i] = v[i-1] ^ derived[i-1];
        }

        if(v[0] ^ v[n-1] == derived[n-1]) return true;

        v[0] = 1;
        for(int i=1; i<n; i++){
            v[i] = v[i-1] ^ derived[i-1];
        }

        return (v[0] ^ v[n-1]) == derived[n-1];
    }
};



// class Solution {
// public:
//     bool doesValidArrayExist(vector<int>& derived) {
//         int ans = 0;
//         for(auto i: derived) ans = ans ^ i;
//         return ans == 0;
//     }
// };