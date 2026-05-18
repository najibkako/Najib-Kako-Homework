#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> numbers2 = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    int originalSize = numbers1.size();

    if (numbers1.size() < numbers2.size()) {
        numbers1.resize(numbers2.size());
    }

    std::vector<int>::iterator it1 = numbers1.begin();
    std::vector<int>::iterator it2 = numbers2.begin();

    int count = 0;

    while (it2 != numbers2.end()) {
        if (count < originalSize) {
            it1++;
            it1 = numbers1.insert(it1, *it2);
            it1++;
        }
        else {
            numbers1.insert(numbers1.end(), *it2);
        }

        it2++;
        count++;
    }

    std::cout << "Interlaced vector (numbers1): ";
    for (int num : numbers1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}