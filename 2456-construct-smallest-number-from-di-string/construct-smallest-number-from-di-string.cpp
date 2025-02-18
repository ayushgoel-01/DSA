class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();

        stack<int> st;
        string ans = "";

        for(int i=1; i<=n+1; i++){
            st.push(i);
            char c = pattern[i-1];

            // If increasing, then reverse it
            if(i == n+1 || c == 'I'){
                while(!st.empty()){
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }
        return ans;
    }
};