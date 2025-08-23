class Solution {
private:
    long long  query(int start, int end, int i, int l, int r, vector<long long>& segTree){
        if(l > end || r < start) return 0;
        if(start <= l && end >= r) return segTree[i];

        int mid = l + (r-l)/2;

        long long left = query(start,end,2*i+1,l,mid,segTree);
        long long right = query(start,end,2*i+2,mid+1,r,segTree);

        return left + right;
    }

    void updateSegmentTree(int idx, int i, int l, int r, vector<long long>& segTree){
        if(l == r){
            segTree[i] = 1;
            return;
        }

        int mid = l + (r-l)/2;

        if(idx <= mid) updateSegmentTree(idx,2*i+1,l,mid,segTree);
        else updateSegmentTree(idx,2*i+2,mid+1,r,segTree);

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        unordered_map<int,int> mp;
        for(int i=0; i<n; i++) mp[nums2[i]] = i;

        vector<long long> segTree(4*n);
        updateSegmentTree(mp[nums1[0]],0,0,n-1,segTree);

        long long ans = 0;
        for(int i=1; i<n; i++){
            int idx = mp[nums1[i]];

            long long leftCommonEl = query(0,idx,0,0,n-1,segTree);
            long long leftUnCommonEl = i - leftCommonEl;
            long long elAfterIdxNums2 = (n-1) - idx;
            long long rightCommonEl = elAfterIdxNums2 - leftUnCommonEl;

            ans += (leftCommonEl * rightCommonEl);
            updateSegmentTree(idx,0,0,n-1,segTree);
        }
        return ans;
    }
};