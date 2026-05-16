class Solution {
private:
    vector<int> solve(vector<int>& a, vector<int>& b){
        vector<int> ans;
        for(int i=0; i<3; i++){
            ans.push_back((a[i]+b[i])/2);
        }
        return ans;
    }
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        int n = points.size();
        set<vector<int>> st;
        for(auto it: points){
            st.insert(it);
        }

        if(st.count(target) >= 1) return 0;
        if(n <= 1) return -1;        

        int k = 0;
        while(true){
            n = points.size();
            k++;
            vector<vector<int>> temp;

            for(int i=0; i<n; i++){
                for(int j=i+1; j<n; j++){
                    vector<int> v = solve(points[i],points[j]);
                    
                    if(st.count(v) <= 0){
                        temp.push_back(v);
                        st.insert(v);
                    }
                    if(st.count(target) >= 1) return k;
                }
            }

            if(temp.empty()) return -1;
            for(auto& it: temp) points.push_back(it);
        }
        return k;
    }
};