#include <iostream>
#include <sstream>
#include <string>
//
using namespace std;
//
void solve();
//
void solve() {
    int N;
    cin >> N;
    getchar();
    while (N--) {
        string line;
        getline(cin, line);
        istringstream iss(line);

        string title;
        int playtime;

        getline(iss, title, ',');
        iss >> playtime;

        int y = playtime / 525600;
        playtime -= y * 525600;
        int d = playtime / 1440;
        playtime -= d * 1440;
        int h = playtime / 60;
        playtime -= h * 60;
        int m = playtime % 60;

        cout << title;
        cout << " - ";
        if (y)
            cout << y << " year(s) ";
        if (d)
            cout << d << " day(s) ";
        if (h)
            cout << h << " hour(s) ";
        if (m)
            cout << m << " minute(s)";
        cout << "\n";
    }
}
//
int main() {
    solve();
    return 0;
}