class Solution {
private:
    vector<int> leftSmaller(vector<int>& arr, int n){
        vector<int> ans(n,0);
        stack<int> st;
        st.push(-1);

        for(int i=0; i<n; i++){
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> rightSmaller(vector<int>& arr, int n){
        vector<int> ans(n,0);
        stack<int> st;
        st.push(-1);

        for(int i=n-1; i>=0; i--){
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> left = leftSmaller(heights,n);
        vector<int> right = rightSmaller(heights,n);

        int area = INT_MIN;
        for(int i=0; i<n; i++){
            int l = heights[i];

            if(right[i] == -1) right[i] = n;
            int b = right[i] - left[i] - 1;
            area = max(area,l*b);
        }
        return area;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> arr(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr[i][j] = matrix[i][j] - '0';
            }
        }

        int area = largestRectangleArea(arr[0]);
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] != 0) arr[i][j] += arr[i-1][j];
            }
            area = max(area,largestRectangleArea(arr[i]));
        }
        return area;
    }
};