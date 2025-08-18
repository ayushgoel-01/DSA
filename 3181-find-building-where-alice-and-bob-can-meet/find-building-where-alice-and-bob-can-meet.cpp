class Solution {            // Using Segment Tree
private:
    void buildSegmentTree(int i, int l, int r, vector<int>& segTree, vector<int>& nums){
        if(l == r){
            segTree[i] = l;
            return;
        }

        int mid = l + (r-l)/2;

        buildSegmentTree(2*i+1,l,mid,segTree,nums);
        buildSegmentTree(2*i+2,mid+1,r,segTree,nums);

        int leftMaxIdx = segTree[2*i+1];
        int rightMaxIdx = segTree[2*i+2];

        segTree[i] = (nums[leftMaxIdx] >= nums[rightMaxIdx]) ? leftMaxIdx : rightMaxIdx;
    }

    int query(int start, int end, int i, int l, int r, vector<int>& segTree, vector<int>& nums){
        if(l > end || r < start) return -1;
        if(l >= start && r <= end){
            return segTree[i];
        }

        int mid = l + (r-l)/2;

        int leftMaxIdx = query(start,end,2*i+1,l,mid,segTree,nums);
        int rightMaxIdx = query(start,end,2*i+2,mid+1,r,segTree,nums);

        if(leftMaxIdx == -1) return rightMaxIdx;
        if(rightMaxIdx == -1) return leftMaxIdx;
        return (nums[leftMaxIdx] >= nums[rightMaxIdx]) ? leftMaxIdx : rightMaxIdx;
    }
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> segTree(4*n);

        buildSegmentTree(0,0,n-1,segTree,heights);

        vector<int> ans;
        for(auto &it: queries){
            int a = it[0];
            int b = it[1];
            if(a > b) swap(a,b);        // Make sure 1st idx <= 2nd idx

            if(a == b){                 // Both are already on same building 
                ans.push_back(a); 
                continue;
            }
            else if(heights[b] > heights[a]){       // 2nd idx building > 1st idx building
                ans.push_back(b);
                continue;
            }

            int start = b + 1;
            int end = n-1;
            int res = -1;

            while(start <= end){                    // Binary Search to find leftMost idx
                int mid = start + (end-start)/2;
                int val = query(start,mid,0,0,n-1,segTree,heights);

                // Check if val height is greater that alice & bob's building
                if(heights[val] > heights[a] && heights[val] > heights[b]){
                    res = val;
                    end = mid-1;
                }
                else start = mid+1;
            }
            ans.push_back(res);
        }
        return ans;
    }
};