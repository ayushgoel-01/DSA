class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = numberOfUsers;
        int m = events.size();

        // Sort according to timeStamps & Process "OFFLINE" query first if timestamps are equal
        auto cmp = [&](vector<string>& a, vector<string>& b){
            if(stoi(a[1]) == stoi(b[1])){
                return a[0] == "OFFLINE";
            }
            return stoi(a[1]) < stoi(b[1]);
        };
        sort(events.begin(),events.end(),cmp);

        vector<int> ans(n,0);
        vector<int> v(n,0);         // Time at which ith ID will go online

        for(int i=0; i<m; i++){
            string event = events[i][0];
            int t = stoi(events[i][1]);
            string ids = events[i][2];

            if(event == "MESSAGE"){
                if(ids == "ALL"){           // Mention all IDs
                    for(int i=0; i<n; i++) ans[i]++;
                }
                else if(ids == "HERE"){         // Mention Online IDs
                    for(int i=0; i<n; i++){
                        if(v[i] <= t){
                            ans[i]++;
                            v[i] = t;
                        }
                    }
                }
                else{
                    stringstream ss(ids);           // Mention provided IDs
                    string token = "";

                    while(getline(ss,token,' ')){
                        int currId = stoi(token.substr(2));
                        ans[currId]++;
                    }
                }
            }
            else{           // Update the cooldown time
                int id = stoi(ids);
                v[id] = t + 60;
            }
        }
        return ans;
    }
};