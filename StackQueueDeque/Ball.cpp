#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, color;
    cin >> n;
    vector<int> balls;
    balls.reserve(n + 1);
    balls.push_back(-1);
    int dead = 0;
    int len = 0;
    int left = 0;
    for (int i = 0; i < n; i++) {
        cin >> color;
        if (color == balls.back()) {
        	len += 1;
            balls.push_back(color);
        }
        else if (len >= 3) {
        	dead += len;
            balls.resize(left);
            balls.push_back(color);
            left = balls.size() - 1;
            len = 1;
            while (balls[left - len] == color) {
            	len += 1;
            }
            left = balls.size() - len;
        }
        else {
        	balls.push_back(color);
            left = balls.size() - 1;
            len = 1;
        }
    }
    if (len >= 3) 
    	dead += len;
    cout << dead;
}
