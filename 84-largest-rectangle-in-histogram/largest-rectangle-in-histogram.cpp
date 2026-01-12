class Solution {
private:
    vector<int> leftSmaller(vector<int>& heights, int n){
        vector<int> ans(n,0);

        stack<int> st;
        st.push(-1);

        for(int i=0; i<n; i++){
            while(st.top() != -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> rightSmaller(vector<int>& heights, int n){
        vector<int> ans(n,0);

        stack<int> st;
        st.push(-1);

        for(int i=n-1; i>=0; i--){
            while(st.top() != -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> left = leftSmaller(heights,n);
        vector<int> right = rightSmaller(heights,n);

        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            int l = heights[i];

            if(right[i] == -1) right[i] = n;
            int b = right[i] - left[i] - 1;

            maxi = max(maxi,l*b);
        }
        return maxi;
    }
};