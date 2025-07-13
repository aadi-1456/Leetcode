#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void bfs(vector<vector<char>>& grid, queue<pair<int,int>> &q, vector<vector<int>>&visited){
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            // Directions for 8 possible moves (up, down, left, right, and diagonals)
            
            vector<int> drow={1,0,-1,0,1,-1,-1,1};
            vector<int> dcol={0,1,0,-1,1,-1,1,-1};
            
            for(int i=0;i<8;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]=='L' && visited[nrow][ncol]==0){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                }
            }
        }
    }
  
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L' && visited[i][j]==0){
                    count++;
                    q.push({i,j});
                    visited[i][j]=1;
                    bfs(grid,q,visited);
                }
            }
        }
        return count;
    }
};