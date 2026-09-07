#include <iostream>
#include <string>

using namespace std;

bool is_anagram(string s1, string s2) {
    if (s1.length() != s2.length()) return false; 
    int buffer[256] = {0};
    
    for (unsigned char c : s1) {
        buffer[c]++;
    }
    
    for (unsigned char c : s2) {
        buffer[c]--;
    }
    
    for (int check : buffer) {
        if (check != 0) return false;
    }
    return true;
}

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    
    if (is_anagram(str1, str2)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}