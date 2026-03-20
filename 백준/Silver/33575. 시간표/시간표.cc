#include <iostream>
#include <vector>
//
using namespace std;
//
int N, M, A, B;
vector<int> subjects;
vector<int> status;
//
long long sum = 0;
//
void calc();
void input();
void output();
void solve();
//
void calc() {
    int cnt_like = 0;
    int cnt_hate = 0;

    for (int i = 0; i < N; i++) {
        int s = subjects[i];

        if (status[s] == 1) {
            cnt_like++;
            cnt_hate = 0;
            if (cnt_like == 3) {
                sum += 3;
            } else if (cnt_like > 3) {
                sum++;
            }
        } else if (status[s] == 2) {
            cnt_hate++;
            cnt_like = 0;
            if (cnt_hate == 3) {
                sum -= 3;
            } else if (cnt_hate > 3) {
                sum--;
            }
        } else {
            cnt_like = 0;
            cnt_hate = 0;
        }
    }
}
//
void input() {
    cin >> N >> M >> A >> B;
    subjects.assign(N, 0);
    status.assign(100001, 0);
    for (int i = 0; i < N; i++) {
        cin >> subjects[i];
    }
    int x;
    for (int i = 0; i < A; i++) {
        cin >> x;
        status[x] = 1;
    }
    for (int i = 0; i < B; i++) {
        cin >> x;
        status[x] = 2;
    }
}
//
void output() {
    cout << sum;
    cout << endl;
}
//
void solve() {
    input();
    calc();
    output();
}
//
int main() {
    solve();
    return 0;
}