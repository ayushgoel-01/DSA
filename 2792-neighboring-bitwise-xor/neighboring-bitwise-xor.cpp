class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int ans = 0;
        for(auto i: derived) ans = ans ^ i;
        return ans == 0;
    }
};