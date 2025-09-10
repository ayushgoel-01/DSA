class Solution {
private:
    bool friends(vector<int>& a, vector<int>& b){
        unordered_set<int> st(a.begin(),a.end());
        for(auto i: b){
            if(st.count(i) >= 1) return true;
        }
        return false;
    }
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> st;

        for(auto &it: friendships){
            int u = it[0] - 1;
            int v = it[1] - 1; 

            if(!friends(languages[u],languages[v])){
                st.insert(u);
                st.insert(v);
            }
        }

        vector<int> freq(n+1,0);
        int maxi = 0;
        for(auto &it: st){
            for(auto j: languages[it]){
                freq[j]++;
                maxi = max(maxi,freq[j]);
            }
        }
        return st.size() - maxi;
    }
};