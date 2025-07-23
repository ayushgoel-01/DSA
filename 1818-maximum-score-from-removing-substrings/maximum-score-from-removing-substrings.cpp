class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();

        int ans = 0;
        stack<char> st;

        if(x >= y){
            for(auto i: s){
                if(i == 'b' && !st.empty() && st.top() == 'a'){
                    ans += x;
                    st.pop();
                }
                else st.push(i);
            }
            string temp = "";
            while(!st.empty()){
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(),temp.end());
            for(auto i: temp){
                if(i == 'a' && !st.empty() && st.top() == 'b'){
                    ans += y;
                    st.pop();
                }
                else st.push(i);
            }
        }
        else{
            for(auto i: s){
                if(i == 'a' && !st.empty() && st.top() == 'b'){
                    ans += y;
                    st.pop();
                }
                else st.push(i);
            }
            string temp = "";
            while(!st.empty()){
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(),temp.end());
            for(auto i: temp){
                if(i == 'b' && !st.empty() && st.top() == 'a'){
                    ans += x;
                    st.pop();
                }
                else st.push(i);
            }
        }
        return ans;
    }
};