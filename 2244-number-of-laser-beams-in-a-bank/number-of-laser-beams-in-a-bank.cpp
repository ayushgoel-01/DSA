class Solution {
private:
    int count(string& s){
        int cnt = 0;
        for(auto i: s){
            if(i == '1') cnt++;
        }
        return cnt;
    }
public:
    int numberOfBeams(vector<string>& bank) {       // optimal
        int ans = 0;
        int prevRow = 0;

        for(auto i: bank){
            int currRow = count(i);
            if(currRow == 0) continue;

            ans += currRow * prevRow;
            prevRow = currRow;
        }
        return ans;
    }
};



// class Solution {     // Brute Force (using freq array)
// public:
//     int numberOfBeams(vector<string>& bank) {
//         int n = bank.size();

//         vector<int> tmp(n,0);       // cnt array of 1's
//         for(int i=0; i<n; i++){
//             string s = bank[i];
//             int cnt = 0;
//             for(int j=0; j<s.size(); j++){
//                 if(s[j] == '1') cnt++;
//             }
//             tmp[i] = cnt;
//         }

//         int ans = 0;
//         int i = 0, j = i+1;
//         while(i < n && j < n){
//             if(tmp[i] != 0 && tmp[j] != 0 && i != j){
//                 ans += tmp[i]*tmp[j];
//                 i = j;
//                 j++;
//             }
//             else if(tmp[i] == 0){
//                 i++;
//                 j++;
//             }
//             else if(tmp[j] == 0) j++;
//         }
//         return ans;
//     }
// };