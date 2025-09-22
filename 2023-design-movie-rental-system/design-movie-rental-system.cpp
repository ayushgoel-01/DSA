class MovieRentingSystem {
#define P pair<int,int>
public:
    unordered_map<int,set<P>> available;            // movie -> price,shop
    unordered_map<int,set<P>> movieToShopPrice;     // movie -> shop,price
    set<tuple<int,int,int>> rented;                 // price, shop, movie

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto& it: entries){
            int shop = it[0];
            int movie = it[1];
            int price = it[2];

            available[movie].insert({price,shop});
            movieToShopPrice[movie].insert({shop,price});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        int cnt = 0;
        if(available.count(movie)){
            for(auto& [price,shop]: available[movie]){
                ans.push_back(shop);
                cnt++;
                if(cnt >= 5) break;
            }
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        auto it = movieToShopPrice[movie].lower_bound({shop,INT_MIN});
        int price = it -> second;
        
        available[movie].erase({price,shop});
        rented.insert({price,shop,movie});
    }
    
    void drop(int shop, int movie) {
        auto it = movieToShopPrice[movie].lower_bound({shop,INT_MIN});
        int price = it -> second;

        rented.erase({price,shop,movie});
        available[movie].insert({price,shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int cnt = 0;

        for(auto& [price,shop,movie]: rented){
            ans.push_back({shop,movie});
            cnt++;
            if(cnt >= 5) break;
        }
        return ans;
    }
};