#include <bits/stdc++.h>
using namespace std;
int main() {
    string line;
    while (getline(cin, line)) {
        while (line.back() == '\r') line.pop_back();
        for (auto i : line) {
            char output = i;
            if (isalpha(i)) {
                if (isupper(i)) {
                    output = (i - 'A' + 13) % 26 + 'A';
                } else if (islower(i)) {
                    output = (i - 'a' + 13) % 26 + 'a';
                }
            }
            cout << output;
        }
        cout << '\n';
    }
}
