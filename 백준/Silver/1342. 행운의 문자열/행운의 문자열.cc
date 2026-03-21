#include <iostream>
#include <vector>
//
using namespace std;
//
vector<int> map(256, 0);
string S;
int sum = 0;
//
void input();
void output();
void solve();
void dfs(char c, int depth);
//
void dfs(char c, int depth) {
    if (depth == S.size()) {
        sum += 1;
        return;
    }

    for (int i = 0; i < 256; i++) {
        if (map[i] == 0 || i == c) {
            continue;
        }
        map[i] -= 1;
        dfs(i, depth + 1);
        map[i] += 1;
    }
}
//
void input() {
    cin >> S;
    for (char c : S) {
        map[c] += 1;
    }
}
//
void output() { cout << sum; }
//
void solve() {
    input();
    dfs('\0', 0);
    output();
}
//
int main() {
    solve();
    return 0;
}
