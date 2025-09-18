auto cmp = [](vector<int>& a, vector<int>& b){ 
    if(a[2] == b[2]) return a[1] <= b[1];
    return a[2] < b[2];                         // Higher priority first
};
class TaskManager {
                // Priority, TaskId, userId
    priority_queue<vector<int>,vector<vector<int>>, decltype(cmp)> pq;  
    unordered_map<int,pair<int,int>> mp;          // TaskId -> {uId,Priority}
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto& it: tasks){
            pq.push(it);
            mp[it[1]] = {it[0],it[2]};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({userId,taskId,priority});
        mp[taskId] = {userId,priority};
    }

    void edit(int taskId, int newPriority) {
        int userId = mp[taskId].first;
        pq.push({userId,taskId,newPriority});
        mp[taskId] = {userId,newPriority};
    }
    
    void rmv(int taskId) {
        mp[taskId].second = -1;
    }
    
    int execTop() {
        while(!pq.empty() && mp[pq.top()[1]].second != pq.top()[2]) pq.pop();
        if(pq.empty()) return -1;

        auto it = pq.top();
        mp[it[1]].second = -1;
        pq.pop();
        return it[0];
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */