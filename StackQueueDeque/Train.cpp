#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, out, len_end, vagon;
    int end[100];
    cin >> n;
    out = 0; len_end = 0;
    for (int i = 0; i < n; i++) {
    	cin >> vagon;
        end[len_end] = vagon;
        len_end += 1;
        while (end[len_end - 1] - 1 == out) {
        	out += 1;
            len_end -= 1;
        }
    }
    if (len_end == 0) {
    	cout << "YES";
    }
    else {
    	cout << "NO";
    }
}
