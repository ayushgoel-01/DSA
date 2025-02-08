class NumberContainers {
public:
    map<int,int> mp;
    unordered_map<int,set<int>> numToIdx;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp.find(index) != mp.end()){
            int num = mp[index];
            numToIdx[num].erase(index);

            if(numToIdx[num].empty()) numToIdx.erase(num);
        }
        mp[index] = number;
        numToIdx[number].insert(index);
    }
    
    int find(int number) {
        if(numToIdx.find(number) != numToIdx.end()){
            return *numToIdx[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */