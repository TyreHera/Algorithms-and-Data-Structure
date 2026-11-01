#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Cargo {
	int arrive;
	int handling;
};

struct Compare {
	bool operator() (const Cargo& a, const Cargo& b) {
		return a.arrive > b.arrive;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<Cargo, vector<Cargo>, Compare> cargos;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
    	Cargo cargo;
        cin >> cargo.arrive;
        cin >> cargo.handling;
        cargos.push(cargo);
    }
    priority_queue<int, vector<int>, greater<int>> devices;
    devices.push(0);
    int count_devices = 0;
    while (cargos.size() > 0) {
    	Cargo cargo = cargos.top(); cargos.pop();
        if (cargo.arrive >= devices.top()) {
        	devices.pop();
        }
        devices.push(cargo.arrive + cargo.handling);
        if (devices.size() > count_devices) {
        	count_devices = devices.size();
        }
    }
    cout << count_devices;
    return 0;
}