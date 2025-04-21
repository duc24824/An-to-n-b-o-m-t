#include <iostream>
#include <map>
#include <cmath>
#include <string>

using namespace std;

double calculate_entropy(const string& text) {
    if (text.empty()) return 0.0;

    map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }

    double entropy = 0.0;
    for (const auto& pair : freq) {
        double p = static_cast<double>(pair.second) / text.size();
        entropy -= p * log2(p);
    }

    return entropy;
}

int main() {
    string input;
    cout << "Enter a string of characters: ";
    getline(cin, input);

    double H = calculate_entropy(input);
    cout << "Entropy: " << H << endl;

    return 0;
}
