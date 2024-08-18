#include <bits/stdc++.h>
using namespace std;

void createAdjList(unordered_map<int , set<int>> &list, vector<vector<int>> edges ){
    for(int i = 0 ; i <  edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        list[u].insert(v);
        list[v].insert(u);
    }
}

void dfs(unordered_map<int , set<int>> &adj,unordered_map < int , bool > &visited,int i,vector<int> &component){
    component.push_back(i);
    visited[i]= 1;

    //har connected node k liye reccursive call
    for(auto j : adj[i]){
        if(!visited[j]){
            dfs(adj,visited,j,component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V , int E , vector<vector<int>> edges){

    unordered_map<int , set<int>> adj;
    createAdjList(adj,edges);

    vector<vector<int>> ans;
    unordered_map < int , bool > visited;
    for(int i = 0 ; i < V ; i++){
        vector<int> component;
        if(!visited[i]){
            dfs(adj,visited,i,component);
            ans.push_back(component);
        }
    }
    return ans;
}
