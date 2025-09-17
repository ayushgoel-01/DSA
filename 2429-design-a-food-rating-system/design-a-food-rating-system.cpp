struct cmp {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;       
    }
};

class FoodRatings {
#define P pair<int,string>
public:
    unordered_map<string,int> mp;
    unordered_map<string,string> foodToCuisine;
    map<string, set<P,cmp>> st;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();

        for(int i=0; i<n; i++){
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            mp[food] = rating;
            st[cuisine].insert({rating,food});
            foodToCuisine[food] = cuisine;
        }
    }
    
    void changeRating(string food, int newRating) {
        int rating = mp[food];
        string cuisine = foodToCuisine[food];

        st[cuisine].erase({rating,food});
        st[cuisine].insert({newRating,food});
        mp[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        P ans = *(st[cuisine].begin());
        return ans.second;
    }
};