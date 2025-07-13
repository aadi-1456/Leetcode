#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int visited[n][m];
        int countFresh = 0;
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    visited[i][j] = 2;
                    q.push({{i, j}, 0});  // Fixed this
                } else {
                    visited[i][j] = 0;
                }
                if (grid[i][j] == 1) {
                    countFresh++;
                }
            }
        }

        int time = 0;
        int drow[4] = {1, 0, -1, 0};  // Fixed syntax
        int dcol[4] = {0, 1, 0, -1};
        int cnt = 0;

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                    visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    
                    q.push({{nrow, ncol}, t + 1});
                    visited[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }

        if (cnt != countFresh) return -1;

        return time;
    }
};



