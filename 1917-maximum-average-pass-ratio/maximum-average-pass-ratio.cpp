class Solution {
private:
    double getDelta(int pass, int total){
        double prev = (double)pass/total;
        double curr = (double)(pass+1)/(total+1);
        return curr - prev;
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double,int>> pq;

        for(int i=0; i<n; i++){
            double delta = getDelta(classes[i][0],classes[i][1]);
            pq.push({delta,i});
        }

        while(!pq.empty() && extraStudents--){
            double delta = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            classes[idx][0]++;
            classes[idx][1]++;

            double currDelta = getDelta(classes[idx][0],classes[idx][1]);
            pq.push({currDelta,idx});
        }

        double ans = 0;
        for(auto it: classes){
            ans += (double)it[0]/it[1];
        }
        return ans/n;
    }
};