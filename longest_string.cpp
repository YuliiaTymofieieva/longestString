// longest_string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool isPredecessor(string& word1, string& word2) {
    if (word1.size() + 1 != word2.size()) {
        return false;
    }

    int i = 0, j = 0;
    bool foundMismatch = false;

    while (i < word1.size() && j < word2.size()) {
        if (word1[i] == word2[j]) {
            i++;
        }
        else {
            if (foundMismatch) {
                return false;
            }
            foundMismatch = true;
        }
        j++;
    }

    return true;
}

int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.size() < b.size();
        });

    unordered_map<string, int> dp;
    int longestChain = 0;

    for (const string& word : words) {
        int maxChain = 0;

        for (int i = 0; i < word.size(); i++) {
            string predecessor = word.substr(0, i) + word.substr(i + 1);

            if (dp.count(predecessor)) {
                maxChain = max(maxChain, dp[predecessor] + 1);
            }
        }

        dp[word] = maxChain;
        longestChain = max(longestChain, maxChain);
    }

    return longestChain + 1;
}

int main() {
    vector<string> words;
    int n;
    cout << "Podaj liczbe slow: ";
    cin >> n;

    cout << "Wprowadz " << n << " slow:" << endl;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    int result = longestStrChain(words);

    cout << "Najdluzszy lancuch slow: " << result << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
