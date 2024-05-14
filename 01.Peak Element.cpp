#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::string line;
    std::getline(std::cin, line); 
    std::istringstream iss(line);
    std::vector<int> numbers;
    int num;

 
    while (iss >> num) {
        numbers.push_back(num);
    }

    int largest_peak = -1;

    for (int i = 0; i < numbers.size(); ++i) {
        if ((i == 0 || numbers[i] > numbers[i - 1]) && 
            (i == numbers.size() - 1 || numbers[i] > numbers[i + 1])) { 
            if (numbers[i] > largest_peak) {
                largest_peak = numbers[i];  
            }
        }
    }

    // Output the largest peak element found
    std::cout << largest_peak << std::endl;

    return 0;
}
