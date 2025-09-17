struct cmp {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;       
    }
};

class FoodRatings {
#define P pair<int,string>
public:
    unordered_map<string,int> mp;
    unordered_map<string,string> foodToCuisine;
    map<string, priority_queue<P,vector<P>,cmp>> pq;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();

        for(int i=0; i<n; i++){
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            mp[food] = rating;
            pq[cuisine].push({rating,food});
            foodToCuisine[food] = cuisine;
        }
    }
    
    void changeRating(string food, int newRating) {
        mp[food] = newRating;
        string cuisine = foodToCuisine[food];
        pq[cuisine].push({newRating,food});
    }
    
    string highestRated(string cuisine) {
        while(!pq[cuisine].empty()){
            int currRating = pq[cuisine].top().first;
            string food = pq[cuisine].top().second;
            int actualRating = mp[food];

            if(currRating == actualRating) break;
            pq[cuisine].pop();
        }
        return pq[cuisine].top().second;
    }
};