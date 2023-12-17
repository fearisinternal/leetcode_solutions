#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

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

int main()
{
    std::vector<std::string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    std::vector<std::string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    std::vector<int> ratings = {9, 12, 8, 15, 14, 7};
    FoodRatings foodRatings = FoodRatings(foods, cuisines, ratings);
    std::cout << foodRatings.highestRated("korean") << std::endl;   // return "kimchi"
                                                                    // "kimchi" is the highest rated korean food with a rating of 9.
    std::cout << foodRatings.highestRated("japanese") << std::endl; // return "ramen"
                                                                    // "ramen" is the highest rated japanese food with a rating of 14.
    foodRatings.changeRating("sushi", 16);                          // "sushi" now has a rating of 16.
    std::cout << foodRatings.highestRated("japanese") << std::endl; // return "sushi"
                                                                    // "sushi" is the highest rated japanese food with a rating of 16.
    foodRatings.changeRating("ramen", 16);                          // "ramen" now has a rating of 16.
    std::cout << foodRatings.highestRated("japanese") << std::endl; // return "ramen"
    return 0;
}