class MovieRentingSystem {
public:
    typedef pair<int, int> P; // {price, shop}
    unordered_map<int, set<P>> available; // movie -> set of {price, shop}
    unordered_map<int, unordered_map<int, int>> priceMap; // movie -> {shop -> price}
    set<tuple<int, int, int>> rented; // {price, shop, movie}

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& entry : entries) {
            int shop = entry[0], movie = entry[1], price = entry[2];
            available[movie].insert({price, shop});
            priceMap[movie][shop] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> result;
        if (available.count(movie)) {
            int count = 0;
            for (auto& [price, shop] : available[movie]) {
                result.push_back(shop);
                if (++count == 5) break;
            }
        }
        return result;
    }

    void rent(int shop, int movie) {
        int price = priceMap[movie][shop];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = priceMap[movie][shop];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        for (auto& [price, shop, movie] : rented) {
            result.push_back({shop, movie});
            if (++count == 5) break;
        }
        return result;
    }
};
