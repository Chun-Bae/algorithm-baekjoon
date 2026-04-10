#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int F, S, G, dir[2];
vector<int> visited;

void bfs(int start) {
  visited[start] = 1;
  queue<int> q;
  q.push(start);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int i = 0; i < 2; i++) {
      int next = cur + dir[i];

      if (next <= 0 || next > F)
        continue;
      if (!visited[next]) {
        visited[next] = visited[cur] + 1;
        q.push(next);
      }
    }
  }
}

void input() {
  cin >> F >> S >> G >> dir[0] >> dir[1];
  dir[1] = -dir[1];
  visited.assign(F + 1, 0);
}

void output() {
  if (visited[G]) {
    cout << visited[G] - 1;
  } else {
    cout << "use the stairs";
  }
}

void solve() {
  input();
  bfs(S);
  output();
}

int main() {
  solve();
  return 0;
}