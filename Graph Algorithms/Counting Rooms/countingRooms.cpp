#include <bits/stdc++.h>
using namespace std;

int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};

int n, m, answer = 0;
int visited[1010][1010];
char grid[1010][1010];

bool isValid (int y, int x) {
  if (y >= 0 && x >=  0 && x < m && y < n && grid[y][x] == '.' ) return true;
  return false;
}

void searchDFS (int y, int x) {
  visited[y][x] = 1;
  for (int i = 0 ; i < 4 ; i++) {
    int newX = x + moveX[i];
    int newY = y + moveY[i];
    if (isValid(newY, newX)) {
      if (!visited[newY][newX]) {
        searchDFS(newY, newX);
      }
    }
  }
}

int main() {
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        cin >> grid[i][j];
        visited[i][j] = 0;
      }
    }
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        if (grid[i][j] == '.' && !visited[i][j]) {
          searchDFS(i, j);
          answer++;
        }
      }
    }
    cout << answer << endl;
    return 0;
}
