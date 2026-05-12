class Solution {
private:
    bool solve(vector<vector<int>>& tasks, int mid){
        int val = mid;
        for(auto it: tasks){
            int actual = it[0];
            int mini = it[1];

            if(mid < mini) return false;
            mid -= actual;
        }
        return true;
    }
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        auto cmp = [&](vector<int>& a, vector<int>& b){
            return (a[1]-a[0]) > (b[1]-b[0]);
        };
        sort(tasks.begin(),tasks.end(),cmp);

        int start = 1, end = 0;
        for(auto it: tasks){
            start = max(start,it[1]);
            end += it[1];
        }

        int ans = end;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(solve(tasks,mid)){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};