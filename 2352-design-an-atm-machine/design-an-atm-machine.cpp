class ATM {
public:
    vector<int> cnt;
    unordered_map<int,int> mp;

    ATM() {
     cnt.resize(5,0);

     mp[0] = 20;
     mp[1] = 50;
     mp[2] = 100;
     mp[3] = 200;
     mp[4] = 500;   
    }

    bool check(int amount){
        for(int i=4; i>=0; i--){
            int note = mp[i];

            if(amount < note || cnt[i] == 0) continue;

            int reqNoteCnt = amount / note; 
            if(reqNoteCnt <= cnt[i]){
                amount -= (reqNoteCnt * note);
            }
            else{
                amount -= (cnt[i] * note);
            }
        }
        return amount == 0;
    }

    vector<int> solve(int amount){
        vector<int> ans(5,0);

        for(int i=4; i>=0; i--){
            int note = mp[i];
            if(amount < note) continue;

            int req = amount / note;
            int fcnt = min(cnt[i],req);
            ans[i] = fcnt;
            amount -= (fcnt * note);
        }

        for(int i=0; i<5; i++){
            cnt[i] -= ans[i];
        }
        return ans;
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0; i<5; i++){
            cnt[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        if(amount < 20) return {-1};

        if(!check(amount)) return {-1};
        return solve(amount);
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */