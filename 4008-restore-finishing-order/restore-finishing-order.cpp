class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> st(friends.begin(),friends.end());

        vector<int> ans;
        for(auto i: order){
            if(st.count(i)) ans.push_back(i);
        }
        return ans;
    }
};