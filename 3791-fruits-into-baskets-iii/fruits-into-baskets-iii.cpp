class Solution {
private:
    void buildSegmentTree(int i, int l, int r, vector<int>& baskets, vector<int>& segTree){
        if(l == r){
            segTree[i] = l;
            return;
        }

        int mid = l + (r-l)/2;

        buildSegmentTree(2*i+1,l,mid,baskets,segTree);
        buildSegmentTree(2*i+2,mid+1,r,baskets,segTree);

        int leftMaxIdx = segTree[2*i+1];
        int rightMaxIdx = segTree[2*i+2];

        segTree[i] = (baskets[leftMaxIdx] >= baskets[rightMaxIdx]) ? leftMaxIdx : rightMaxIdx;
    }

    int query(int start, int end, int i, int l, int r, vector<int>& baskets, vector<int>& segTree){
        if(end < l || start > r) return -1;
        if(start <= l && end >= r){
            return segTree[i];
        }

        int mid = l + (r-l)/2;

        int leftMaxIdx = query(start,end,2*i+1,l,mid,baskets,segTree);
        int rightMaxIdx = query(start,end,2*i+2,mid+1,r,baskets,segTree);

        if(leftMaxIdx == -1) return rightMaxIdx;
        if(rightMaxIdx == -1) return leftMaxIdx;

        return (baskets[leftMaxIdx] >= baskets[rightMaxIdx]) ? leftMaxIdx : rightMaxIdx;
    }

    void updateSegmentTree(int idx, int i, int l, int r, vector<int>& baskets, vector<int>& segTree){
        if(l == r){
            segTree[i] = -1;
            return;
        }

        int mid = l + (r-l)/2;

        if(idx <= mid){
            updateSegmentTree(idx,2*i+1,l,mid,baskets,segTree);
        }
        else{
            updateSegmentTree(idx,2*i+2,mid+1,r,baskets,segTree);
        }

        int leftMaxIdx = segTree[2*i+1];
        int rightMaxIdx = segTree[2*i+2];

        if(leftMaxIdx == -1) segTree[i] = rightMaxIdx;
        else if(rightMaxIdx == -1) segTree[i] = leftMaxIdx;
        else segTree[i] = (baskets[leftMaxIdx] >= baskets[rightMaxIdx]) ? leftMaxIdx : rightMaxIdx;
    }
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> segTree(4*n);

        buildSegmentTree(0,0,n-1,baskets,segTree);

        int ans = 0;
        for(int i=0; i<n; i++){
            int start = 0, end = n-1;
            int idx = -1;
            while(start <= end){
                int mid = start + (end - start)/2;
                int val = query(start,mid,0,0,n-1,baskets,segTree);

                if(val != -1 && baskets[val] >= fruits[i]){
                    idx = val;
                    end = mid-1;
                }
                else start = mid+1;
            }

            if(idx != -1){
                ans++;
                updateSegmentTree(idx,0,0,n-1,baskets,segTree);
            }
        }

        return n - ans;
    }
};