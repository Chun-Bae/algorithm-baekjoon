#include <iostream>
#include <vector>

using namespace std;

void input();
void calc();
void output();
void solve();

int N, M;
int max_n, min_n;
int result;
char max_who;
string A, B;
vector<int> chemi;

vector<int> st = {3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3,
                  2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
void calc() {
    int len = N + M;
    for (int j = 0; j < len - 2; j++) {
        for (int i = 0; i < N + M - j; i++)
            chemi[i] = (chemi[i] + chemi[i + 1]) % 10;
    }
    result = chemi[0] * 10 + chemi[1];
}

void input() {
    cin >> N >> M;
    cin >> A >> B;
    max_n = N > M ? N : M;
    max_who = N > M ? 'A' : 'B';
    min_n = N > M ? M : N;
    for (int i = 0; i < min_n; i++) {
        chemi.push_back(st[A[i] - 'A']);
        chemi.push_back(st[B[i] - 'A']);
    }
    for (int i = min_n; i < max_n; i++) {
        if (max_who == 'A') {
            chemi.push_back(st[A[i] - 'A']);
        } else {
            chemi.push_back(st[B[i] - 'A']);
        }
    }
}

void output() { cout << result << '%'; }

void solve() {
    input();
    calc();
    output();
}

int main() {
    solve();
    return 0;
}