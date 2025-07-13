#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bfs(int node,vector<vector<int>>& graph,vector<int>&color){
        queue<int> q;
        q.push(node);
        color[node]=0;
        
        while(!q.empty()){
            int vert=q.front();
            q.pop();

            for(auto it: graph[vert]){
                if(color[it]==-1){
                    color[it]=!color[vert];
                    q.push(it);
                }
                else if(color[it]==color[vert]){
                    return false;
                }
            }
        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bfs(i,graph,color) == false){
                    return false;
                }
            }
        }
        return true;
    }
};