#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>

std::vector<int> kLargestElements(const std::vector<int>& arr, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;


    for (int i = 0; i < k; ++i) {
        minHeap.push(arr[i]);
    }

   
    for (int i = k; i < arr.size(); ++i) {
        if (arr[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }

   
    std::vector<int> result;
    result.reserve(k);
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<int> myArray((std::istream_iterator<int>(iss)), std::istream_iterator<int>());

    int k;
    std::cin >> k;

    std::vector<int> result = kLargestElements(myArray, k);

  
    std::sort(result.begin(), result.end());

    for (int element : result) {
        std::cout << element << std::endl;
    }

    return 0;
}
