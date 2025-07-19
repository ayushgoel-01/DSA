class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();

        sort(folder.begin(),folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);

        for(int i=1; i<n; i++){
            string curr = folder[i];
            string prev = ans.back();
            prev += "/";

            if(curr.find(prev) != 0){
                ans.push_back(curr);
            }
        }
        return ans;
    }
};