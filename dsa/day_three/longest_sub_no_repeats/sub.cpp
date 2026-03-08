#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int main() {
    std::string word;
    std::cout << "Enter the word: ";
    std::cin >> word;

    std::unordered_map<char, int> lastSeen;
    int maxLen = 0;

    for (int l = 0, r = 0; r < word.size(); r++) {

        if (lastSeen.count(word[r]) && lastSeen[word[r]] >= l) {
            l = lastSeen[word[r]] + 1;
        }

        lastSeen[word[r]] = r;
        maxLen = std::max(maxLen, r - l + 1);
    }

    std::cout << maxLen << '\n';
}

