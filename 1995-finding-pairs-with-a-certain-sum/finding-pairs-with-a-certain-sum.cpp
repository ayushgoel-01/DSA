class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int,int> mp1, mp2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this -> nums1 = nums1;
        this -> nums2 = nums2;
        
        for(auto i: nums1) mp1[i]++;
        for(auto i: nums2) mp2[i]++;
    }
    
    void add(int index, int val) {
        int prev = nums2[index];
        nums2[index] += val;
        mp2[prev]--;
        mp2[prev+val]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto& i: mp1){
            int val = i.first;
            int freq = i.second;

            ans += (mp2[tot-val] * freq);
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */