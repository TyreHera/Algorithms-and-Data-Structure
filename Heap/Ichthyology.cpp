#include <iostream>
#include <queue>
#include <vector>

#define fish_time(x) (max(1000-aquariums[(x)], 1))

using namespace std;

struct Record {
	int time;
	int aquarium;
};

struct Compare {
	bool operator() (const Record& a, const Record& b) {
		return a.time > b.time;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<Record, vector<Record>, Compare> records;
    int n;
    cin >> n;
    int* aquariums = new int[n];
    for (int i = 0; i < n; i++) {
    	cin >> aquariums[i];
        records.push({fish_time(i), i+1});
    }
    int time = 0;
    int position = 1;
    while (true) {
    	Record record = records.top();
        if (time + abs(position - record.aquarium) <= record.time) {
        	time = record.time;
            position = record.aquarium;
            aquariums[position-1] += 1;
            records.pop();
            records.push({time+fish_time(position-1), position});
        }
        else break;
    }
    cout << records.top().time;
    delete [] aquariums;
}