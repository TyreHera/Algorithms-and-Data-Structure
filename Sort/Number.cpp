#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> parts;
    string current_str;

    while (cin >> current_str)
    {
        parts.push_back(current_str);
    }

    sort(parts.begin(), parts.end(), [](const string &a, const string &b) {
        return (a + b) > (b + a);
    });

    for (const auto &part : parts)
    {
        cout << part;
    }
    
    return 0;
}
