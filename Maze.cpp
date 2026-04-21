#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> maze(n);

    for(int i = 0; i < n; i++) {
        cin >> maze[i];
    }

    int start_i, start_j;
    int dest_i, dest_j;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maze[i][j] == 'R') {
                start_i = i;
                start_j = j;
            }
            if(maze[i][j] == 'D') {
                dest_i = i;
                dest_j = j;
            }
        }
    }

    int di[4] = {0, 0, -1, 1};
    int dj[4] = {1, -1, 0, 0};

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1, -1}));

    queue<pair<int,int>> q;

    q.push({start_i, start_j});
    visited[start_i][start_j] = true;

    bool path_found = false;

    while(!q.empty()) {
        int current_i = q.front().first;
        int current_j = q.front().second;
        q.pop();

        if(current_i == dest_i && current_j == dest_j) {
            path_found = true;
            break;
        }

        for(int k = 0; k < 4; k++) {
            int ni = current_i + di[k];
            int nj = current_j + dj[k];

            if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
                if(!visited[ni][nj] && maze[ni][nj] != '#') {
                    visited[ni][nj] = true;
                    parent[ni][nj] = {current_i, current_j};
                    q.push({ni, nj});
                }
            }
        }
    }

    if(path_found) {
        int ci = dest_i;
        int cj = dest_j;

        while(!(ci == start_i && cj == start_j)) {
            if(maze[ci][cj] != 'D' && maze[ci][cj] != 'R') {
                maze[ci][cj] = 'X';
            }

            int pi = parent[ci][cj].first;
            int pj = parent[ci][cj].second;

            ci = pi;
            cj = pj;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << maze[i] << endl;
    }

    return 0;
}