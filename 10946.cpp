#include <bits/stdc++.h>

using namespace std;

int n, m;
char s[50][50];
bool vis[50][50];
vector<int> v[26];
bool inside(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m;
}
int cnt = 0;
void dfs(char color, int i, int j) {
  if (vis[i][j])
    return;
  cnt++;
  vis[i][j] = true;
  for (int x = -1; x <= 1; x++) {
    for (int y = -1; y <= 1; y++) {
        if (x == 0 && y == 0 || abs(x) + abs(y) == 2)
          continue;
        int go_x = i + x;
        int go_y = j + y;
   
        if (inside(go_x, go_y) && s[go_x][go_y] == color) {
          dfs(color, go_x, go_y);
        }

    }
  }

}

void read() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> s[i][j];
}

void clr() {
  for (int i = 0; i < 26; i++)
      v[i].clear();
  memset(vis, false, sizeof(vis));

}

bool cmp(pair<int, char> p1, pair<int, char> p2) {
  if (p1.first != p2.first)
    return p1.first > p2.first;
  return p1.second < p2.second;
}
int main() {
  int p = 1;
  while (cin >> n >> m) {
    if (n == 0 && m == 0)
      break;
    clr();
    read();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (isalpha(s[i][j])) {
          cnt = 0;
          dfs(s[i][j], i, j);
          v[s[i][j] - 'A'].push_back(cnt);
        }
      }
    vector<pair<int, char>> ans;
    for (int i = 0; i < 26; i++) {
      if (v[i].empty()) continue;
      for (auto x : v[i])
        if (x > 0)
          ans.push_back({x, char('A' + i)});
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << "Problem " << p++ << ":\n";
    for (auto x : ans) {
      cout << x.second << " " << x.first << "\n";
    }


  }
  return 0;
}
