#include <iostream>
//
using namespace std;
//
string name;
int n;
//
void solve();
//
void solve() {
    cin >> name;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string nm;
        cin >> nm;
        for (int c = 0; c < nm.size(); c++) {
            char tmp = name[c];
            name[c] = nm[c];
            if (nm == name) {
                cout << i + 1;
                return;
            } else {
                name[c] = tmp;
            }
        }
    }
}
//
int main() {
    solve();
    return 0;
}