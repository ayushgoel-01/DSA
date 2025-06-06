class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();

        vector<char> v(n);
        v[n-1] = s[n-1];
        for(int i=n-2; i>=0; i--){
            v[i] = min(s[i],v[i+1]);
        }

        string ans = "", t = "";
        for(int i=0; i<n; i++){
            t += s[i];

            char mini = (i+1 < n) ? v[i+1] : s[i];
            while(!t.empty() && t.back() <= mini){
                ans += t.back();
                t.pop_back();
            }
        }

        while(!t.empty()){
            ans += t.back();
            t.pop_back();
        }
        return ans;
    }
};