class Solution {
private:
    int findPivot(vector<int>& nums, int n){
        int start = 0, end = n-1;
        while(start < end){
            int mid = (start + end)/2;
            if(nums[mid] > nums[end]){
                start = mid+1;
            }
            else end = mid;
        }
        return end;
    }
    
    int binarySearch(int start, int end, vector<int>& nums, int target){
        while(start <= end){
            int mid = (start + end)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) end = mid-1;
            else start = mid+1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivotIdx = findPivot(nums,n);

        int idx = binarySearch(0,pivotIdx-1,nums,target);
        if(idx != -1) return idx;
        
        idx = binarySearch(pivotIdx,n-1,nums,target);
        return idx;
    }
};