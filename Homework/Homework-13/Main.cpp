#include <iostream>
#include <map>
#include <vector>

int main() {
    // Initialize the two maps
    std::map<int, std::vector<int>> numbers1 = {
        {1, {1}}, {2, {2}}, {3, {3}},
        {4, {4}}, {5, {5}}, {6, {6}},
        {7, {7}}, {8, {8}}, {9, {9}}
    };

    std::map<int, int> numbers2 = {
        {1, 10}, {2, 20}, {3, 30},
        {4, 40}, {5, 50}, {6, 60},
        {7, 70}, {8, 80}, {9, 90}
    };

    // Interlace the maps using iterators
    std::map<int, std::vector<int>>::iterator it1 = numbers1.begin();
    std::map<int, int>::iterator it2 = numbers2.begin();

    while (it1 != numbers1.end() && it2 != numbers2.end()) {
        it1->second.push_back(it2->second);

        ++it1;
        ++it2;
    }

    // If numbers2 has extra elements, add them to numbers1
    while (it2 != numbers2.end()) {
        numbers1[it2->first].push_back(it2->second);
        ++it2;
    }

    // Print the interlaced map
    std::cout << "Interlaced map (numbers1): ";
    for (const auto& pair : numbers1) {
        std::cout << pair.first << ": ";

        for (int i = 0; i < pair.second.size(); i++) {
            std::cout << pair.second[i];

            if (i < pair.second.size() - 1) {
                std::cout << ", ";
            }
        }

        std::cout << " ";
    }

    std::cout << std::endl;

    return 0;
}