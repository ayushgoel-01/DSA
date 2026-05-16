class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        int minIdx = 0;

        while(start <= end){
            while(start < end && nums[start] == nums[start+1]) start++;
            while(start < end && nums[end] == nums[end-1]) end--;

            int mid = (start + end)/2;

            if(nums[mid] < nums[minIdx]){
                minIdx = mid;
            }
            else if(nums[mid] > nums[end]) start = mid+1;
            else end = mid-1;
        }
        return nums[minIdx];
    }
};