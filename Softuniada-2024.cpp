#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::string line;
    std::getline(std::cin, line);  // Read a line of input
    std::istringstream iss(line);
    std::vector<int> numbers;
    int num;

    // Read integers from the input line
    while (iss >> num) {
        numbers.push_back(num);
    }

    int largest_peak = -1;

    // Check for a peak element
    for (int i = 0; i < numbers.size(); ++i) {
        if ((i == 0 || numbers[i] > numbers[i - 1]) &&  // First element or greater than the previous
            (i == numbers.size() - 1 || numbers[i] > numbers[i + 1])) {  // Last element or greater than the next
            if (numbers[i] > largest_peak) {
                largest_peak = numbers[i];  // Update the largest peak found
            }
        }
    }

    // Output the largest peak element found
    std::cout << largest_peak << std::endl;

    return 0;
}
