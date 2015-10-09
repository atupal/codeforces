#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int v[8010], d[8010], p[8010];
int exited[8010];

vector<int> output;

void solve() {
  sort(output.begin(), output.end());
  cout << output.size() << endl;
  for (int i = 0; i < output.size(); ++i) {
    cout << output[i];
    if (i != output.size() - 1) cout << " ";
    else cout << endl;
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> v[i] >> d[i] >> p[i];
  }
  for (int i = 0; i < n; ++i) {
    if (exited[i]) continue;
    output.push_back(i + 1);
    queue<int> q;
    int tmp = v[i], cnt = 1;
    while (tmp) {
      if (exited[i + cnt]) {
        cnt++;
        continue;
      }
      if (i + cnt > n) break;
      p[i + cnt] -= tmp;
      if (p[i + cnt] < 0) { q.push(i + cnt); exited[i + cnt] = true; }
      cnt++; tmp--;
    }

    while (q.size()) {
      int cur = q.front();
      q.pop();
      for (int j = cur + 1; j < n; ++j) {
        if (!exited[j]) {
          p[j] -= d[cur];
          if (p[j] < 0) {
            q.push(j);
            exited[j] = true;
          }
        }
      }
    }
  }

  solve();

  return 0;
}

