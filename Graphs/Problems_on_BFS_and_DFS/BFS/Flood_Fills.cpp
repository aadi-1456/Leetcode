#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int initalcolor=image[sr][sc];
        vector<vector<int>> visited(n,vector<int>(m,0));

        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc]=1;
        image[sr][sc]=color;
        vector<int> drow={1,0,-1,0};
        vector<int> dcol={0,1,0,-1};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(ncol>=0 && ncol<m && nrow>=0 && nrow<n && visited[nrow][ncol]!=1 && image[nrow][ncol]==initalcolor){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                    image[nrow][ncol]=color;
                }
            }

        }

        return image;
    }
};