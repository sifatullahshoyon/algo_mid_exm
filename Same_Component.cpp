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

void dfs(int si, int sj) {
    visited[si][sj] = true;

    for(int k = 0; k < 4; k++) {
        int ni = si + di[k];
        int nj = sj + dj[k];

        if(valid(ni, nj)) {
            dfs(ni, nj);
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int si, sj, dii, djj;
    cin >> si >> sj;
    cin >> dii >> djj;

    if(grid[si][sj] == '-' || grid[dii][djj] == '-') {
        cout << "NO" << endl;
        return 0;
    }

    dfs(si, sj);

    if(visited[dii][djj])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}