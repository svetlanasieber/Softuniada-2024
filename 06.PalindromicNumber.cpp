#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

string findLargestPalindromicPermutation(const string& num) {
    unordered_map<char, int> freq;
    for (char digit : num) {
        freq[digit]++;
    }

    int oddCount = 0;
    char midChar;
    string half;

    for (auto& p : freq) {
        if (p.second % 2 == 1) {
            oddCount++;
            midChar = p.first;  
        }
        half += string(p.second / 2, p.first);
    }

    if (oddCount > 1) {
        return "No palindromic number available.";
    }

   
    sort(half.rbegin(), half.rend());

    string palindrome = half;
    if (oddCount == 1) {
        palindrome += midChar;
    }
    reverse(half.begin(), half.end());
    palindrome += half;

    return palindrome;
}

int main() {
    string N;
    cin >> N;

    string result = findLargestPalindromicPermutation(N);
    cout << result << endl;

    return 0;
}
