#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <iterator>
#include <algorithm>
#include <sstream> // Explicitly include sstream for std::istringstream

std::vector<int> kLargestElements(std::vector<int>& arr, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int i = 0; i < k; ++i) {
        minHeap.push(arr[i]);
    }

    for (size_t i = k; i < arr.size(); ++i) {
        if (arr[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }

    std::vector<int> result(k);
    for (int i = k - 1; i >= 0; --i) {
        result[i] = minHeap.top();
        minHeap.pop();
    }

    return result;
}

int main() {
    std::vector<int> myArray;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int number;

    while (iss >> number) {
        myArray.push_back(number);
    }

    int k;
    std::cin >> k;

    std::vector<int> result = kLargestElements(myArray, k);

    for (int element : result) {
        std::cout << element << std::endl;
    }

    return 0;
}
