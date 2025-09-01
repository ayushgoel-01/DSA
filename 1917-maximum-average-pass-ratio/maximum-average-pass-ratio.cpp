class Solution {
private:
    double getDelta(int pass, int total){
        double prev = (double)(pass/(double)total);
        double curr = (double)((pass+1)/(double)(total+1));
        double delta = curr - prev;
        return delta;
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<pair<double,int>> pq;

        for(int i=0; i<n; i++){
            int pass = classes[i][0];
            int total = classes[i][1];

            double delta = getDelta(pass,total);
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
            int pass = it[0];
            int total = it[1];

            double ratio = (double)pass/(double)total;
            ans += ratio;
        }
        ans = ans/(double)n;
        return ans;
    }
};