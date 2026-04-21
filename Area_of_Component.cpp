#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool visited[1005][1005];

int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

bool valid(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m)
        return false;
    if(grid[i][j] == '-')
        return false;
    if(visited[i][j])
        return false;
    return true;
}

int dfs(int si, int sj) {
    visited[si][sj] = true;
    int count = 1;

    for(int k = 0; k < 4; k++) {
        int ni = si + di[k];
        int nj = sj + dj[k];

        if(valid(ni, nj)) {
            count += dfs(ni, nj);
        }
    }

    return count;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int min_area = INT_MAX;
    bool found = false;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '.' && !visited[i][j]) {
                int area = dfs(i, j);
                min_area = min(min_area, area);
                found = true;
            }
        }
    }

    if(!found)
        cout << -1 << endl;
    else
        cout << min_area << endl;

    return 0;
}