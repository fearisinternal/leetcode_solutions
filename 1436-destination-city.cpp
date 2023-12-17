#include <map>
#include <iostream>
#include <vector>
#include <string>

std::string destCity(std::vector<std::vector<std::string>> &paths)
{
    std::map<std::string, int> points;
    for (auto path : paths)
    {
        points[path[0]]--;
        points[path[1]]++;
    }
    for (auto i : points)
    {
        if (i.second > 0) return i.first;
    }
    return "";
}

int main()
{
    std::vector<std::vector<std::string>> paths = {{"B","C"}};
    std::cout << destCity(paths);
    return 0;
}