class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> mp;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto node = q.front().first;
            int vd = q.front().second.first;
            int hd = q.front().second.second;
            q.pop();

            mp[vd][hd].insert(node -> val);

            if(node -> left) q.push({node -> left,{vd-1,hd+1}});
            if(node -> right) q.push({node -> right,{vd+1,hd+1}});
        }

        for(auto it: mp){
            vector<int> ds;
            for(auto j: it.second){
                for(auto k: j.second) ds.push_back(k);
            }
            ans.push_back(ds);
        }
        return ans;
    }
};