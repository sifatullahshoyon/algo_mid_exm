#include <bits/stdc++.h>
using namespace std;

int n, m;

int di[8] = {-2, -2, 2, 2, 1, 1, -1, -1};
int dj[8] = {1, -1, 1, -1, 2, -2, 2, -2};

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int bfs(int si, int sj, int dii, int djj) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    queue<pair<pair<int,int>, int>> q;
    q.push({{si, sj}, 0});
    visited[si][sj] = true;

    while(!q.empty()) {
        int ci = q.front().first.first;
        int cj = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        if(ci == dii && cj == djj) {
            return steps;
        }

        for(int k = 0; k < 8; k++) {
            int ni = ci + di[k];
            int nj = cj + dj[k];

            if(valid(ni, nj) && !visited[ni][nj]) {
                visited[ni][nj] = true;
                q.push({{ni, nj}, steps + 1});
            }
        }
    }

    return -1;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m;

        int ki, kj, qi, qj;
        cin >> ki >> kj;
        cin >> qi >> qj;

        cout << bfs(ki, kj, qi, qj) << endl;
    }

    return 0;
}