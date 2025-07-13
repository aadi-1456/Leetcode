#include <bits/stdc++.h>

class Solution {
public:
    void bfs(int node, vector<vector<int>>& isConnected,vector<int>& visited){
        visited[node]=1;
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int first=q.front();
            q.pop();

            for(int i=0;i<isConnected.size();i++){
                if(visited[i]!=1 && isConnected[first][i]==1){
                    visited[i]=1;
                    q.push(i);
                }
            }
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n,0);

        int totalProvinces=0;
        for(int i=0;i<n;i++){
            if(visited[i]!=1){
                totalProvinces++;
                bfs(i,isConnected,visited);
            }
        }
        return totalProvinces;
    }
};