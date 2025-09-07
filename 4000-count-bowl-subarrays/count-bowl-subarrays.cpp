class Solution {
private:
    vector<int> nextGreaterRight(vector<int>& nums, int n){
        vector<int> ans(n,-1);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && nums[i] >= nums[st.top()]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nextGreaterLeft(vector<int>& nums, int n){
        vector<int> ans(n,-1);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && nums[i] > nums[st.top()]){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> left = nextGreaterLeft(nums,n);
        vector<int> right = nextGreaterRight(nums,n);

        long long ans = 0;
        for(int i=0; i<n; i++){
            int l = left[i];
            if(l != -1 && i-l+1 >= 3) ans++;

            int r = right[i];
            if(r != -1 && r-i+1 >= 3) ans++;
        }
        return ans;
    }
};