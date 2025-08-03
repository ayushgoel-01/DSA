class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        bool inc = false, dec = false, inc2 = false;

        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                if(inc == false) inc = true;
                else if(dec == true) inc2 = true;
            }
            else if(nums[i] == nums[i-1]) return false;
            else{
                if(inc == false || inc2 == true) return false;
                else dec = true;
            }
        }
        return inc && dec && inc2;
    }
};