class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if(n <= 2) return false;

        for(int i=2; i<n; i++){
            if(arr[i-2] % 2 + arr[i-1] % 2 + arr[i] % 2 == 3) return true;
        }
        return false;
    }
};