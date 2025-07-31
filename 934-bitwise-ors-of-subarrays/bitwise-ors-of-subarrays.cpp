class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();

        unordered_set<int> ans, prev, curr;
        for(int i=0; i<n; i++){

            for(auto x: prev){
                ans.insert(arr[i] | x);
                curr.insert(arr[i] | x);
            }
            ans.insert(arr[i]);
            curr.insert(arr[i]);
            prev = curr;
            curr.clear();
        }
        return ans.size();
    }
};