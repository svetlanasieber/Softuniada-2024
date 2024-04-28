#include <iostream>
#include <string>

void printRow(int sideDots, int midHashes) {
    std::cout << std::string(sideDots, '.') << std::string(midHashes, '#') << std::string(sideDots, '.') << std::endl;
}

void solve(int size) {
    // Top half full cup - N/2 rows
    // Top half partial cup - N/2 + 1 rows
    for (int i = 0; i < size + 1; ++i) {
        int sideSize = size + i;
        int midSize = size * 3 - (i * 2);

        if (i >= size / 2) {
            midSize -= 2;
            std::cout << std::string(sideSize, '.') << "#" << std::string(midSize, '.') << "#" << std::string(sideSize, '.') << std::endl;
        }
        else {
            printRow(sideSize, midSize);
        }
    }

    // Top of body transition line - 1 row
    printRow(size * 2, size);

    // Top of body N / 2 rows
    for (int i = 0; i < size / 2; ++i) {
        int midSize = size + 4;
        int sideSize = size * 2 - 2;
        printRow(sideSize, midSize);
    }

    // Logo
    std::string dance = "D^A^N^C^E^";
    int sideSize = (size * 5 - dance.length()) / 2;
    std::cout << std::string(sideSize, '.') << dance << std::string(sideSize, '.') << std::endl;

    // Bottom of body N / 2 + 1 rows
    for (int i = 0; i < (size / 2) + 1; ++i) {
        int midSize = size + 4;
        int sideSize = size * 2 - 2;
        printRow(sideSize, midSize);
    }
}

int main() {
    int n;
    std::cin >> n;

    if (n % 2 == 0 && n >= 6 && n <= 100) {
        solve(n);
    }
    else {
        std::cout << "Invalid input. Please enter an even number between 6 and 100." << std::endl;
    }

    return 0;
}
