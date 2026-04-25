class Solution {
private:
    int findPivot(int start, int end, vector<int>& nums){
        while(start < end){
            while(start < end && nums[start] == nums[start+1]) start++;
            while(start < end && nums[end] == nums[end-1]) end--;

            int mid = (start + end)/2;
            if(nums[mid] > nums[end]) start = mid+1;
            else end = mid;
        }
        return end;
    }

    bool binarySearch(int start, int end, vector<int>& nums, int target){
        while(start <= end){
            int mid = (start + end)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] > target) end = mid-1;
            else start = mid+1;
        }
        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivotIdx = findPivot(0,n-1,nums);

        if(binarySearch(0,pivotIdx-1,nums,target)) return true;
        return binarySearch(pivotIdx,n-1,nums,target);
    }
};