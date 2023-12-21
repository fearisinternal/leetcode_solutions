class FoodRatings
{
private:
    std::unordered_map<std::string, int> foodToRating;
    std::unordered_map<std::string, std::string> foodToCuisine;
    std::unordered_map<std::string, std::set<std::pair<int, std::string>>> cuisineToFood;

public:
    FoodRatings(std::vector<std::string> &foods, std::vector<std::string> &cuisines, std::vector<int> &ratings)
    {
        for (auto i = 0; i < foods.size(); ++i)
        {
            foodToRating[foods[i]] = ratings[i];
            foodToCuisine[foods[i]] = cuisines[i];
            cuisineToFood[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(std::string food, int newRating)
    {
        auto oldRating = foodToRating[food];
        foodToRating[food] = newRating;
        auto cuisineName = foodToCuisine[food];
        cuisineToFood[cuisineName].erase({-1 * oldRating, food});
        cuisineToFood[cuisineName].insert({-1 * newRating, food});
    }

    std::string highestRated(std::string cuisine)
    {
        return cuisineToFood[cuisine].begin()->second;
    }
};