class Router {
public:
    int n;
    queue<string> q;
    unordered_map<string,vector<int>> mp;
    unordered_map<int,vector<int>> destTime;
    Router(int memoryLimit) {
        this -> n = memoryLimit;
    }

    string getKey(int a, int b, int c){
        return to_string(a) + "_" + to_string(b) + "_" + to_string(c);
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key = getKey(source,destination,timestamp);
        if(mp.find(key) != mp.end()) return false;

        if(q.size() >= n) forwardPacket();

        q.push(key);
        mp[key] = {source,destination,timestamp};
        destTime[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};

        auto key = q.front();
        q.pop();
        auto values = mp[key];
        mp.erase(key);

        int dest = values[1];
        destTime[dest].erase(destTime[dest].begin());
        return values;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = destTime.find(destination);
        if(it == destTime.end() || it -> second.empty()) return 0;

        vector<int>&  v = it -> second;
        int start = lower_bound(v.begin(),v.end(),startTime) - v.begin();
        int end = upper_bound(v.begin(),v.end(),endTime) - v.begin();
        return end - start;
    }
};