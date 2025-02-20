class Solution {
private:
    void solve(int n, string temp, vector<string>& ans){
        if(n <= 0){
            ans.push_back(temp);
            return;
        }

        solve(n-1,temp+"0",ans);
        solve(n-1,temp+"1",ans);
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        unordered_set<string> st(nums.begin(),nums.end());

        vector<string> ans;
        solve(n,"",ans);

        for(auto it: ans){
            if(st.count(it) <= 0) return it;
        }
        return "";
    }
};