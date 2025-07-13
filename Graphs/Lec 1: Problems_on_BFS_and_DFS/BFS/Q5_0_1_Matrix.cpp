#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> visited(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]!=0 && mat[i][j]==0){
                    visited[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        vector<int> drow={1,0,-1,0};
        vector<int> dcol={0,-1,0,1};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];

                if(ncol>=0 && ncol<m && nrow>=0 && nrow<n){
                    if(visited[nrow][ncol]>visited[r][c]){
                        visited[nrow][ncol]=visited[r][c]+1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }

        return visited;
    }
};