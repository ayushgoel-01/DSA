class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;

        long long sum = 0;
        for(int i=1; i<n; i++){
            ans.push_back(i);
            sum += i;
        }
        ans.push_back(-1 * sum);
        return ans;
    }
};