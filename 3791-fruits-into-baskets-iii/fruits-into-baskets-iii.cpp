class Solution {
private:
    void buildSegmentTree(int i, int l, int r, vector<int>& baskets, vector<int>& segTree){
        if(l == r){
            segTree[i] = baskets[l];
            return;
        }

        int mid = l + (r-l)/2;

        buildSegmentTree(2*i+1,l,mid,baskets,segTree);
        buildSegmentTree(2*i+2,mid+1,r,baskets,segTree);

        segTree[i] = max(segTree[2*i+1],segTree[2*i+2]);
    }

    bool query(int i, int l, int r, int fruit, vector<int>& segTree){
        if(segTree[i] < fruit) return false;
        if(l == r){
            segTree[i] = -1;
            return true;
        }

        int mid = l + (r-l)/2;

        bool placed = false;
        if(segTree[2*i+1] >= fruit){
            placed = query(2*i+1,l,mid,fruit,segTree);
        }
        else{
            placed = query(2*i+2,mid+1,r,fruit,segTree);
        }

        segTree[i] = max(segTree[2*i+1],segTree[2*i+2]);
        return placed;
    }
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> segTree(4*n,-1);

        buildSegmentTree(0,0,n-1,baskets,segTree);

        int ans = 0;
        for(int i=0; i<n; i++){
            if(query(0,0,n-1,fruits[i],segTree) == false){
                ans++;
            }
        }
        return ans;
    }
};