#include<bits/stdc++.h>
using namespace std;

void adjMaker(unordered_map<int , set<int>> &list, vector<pair<int,int>> edges ){
    for(int i = 0 ; i <  edges.size() ; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        list[u].insert(v);
        list[v].insert(u);
    }
}

void bfsTraversal(unordered_map<int , set<int>> &adjlist, unordered_map<int , bool> &visited , vector<int> &ans , int i){
    queue<int> q;
    q.push(i);
    visited[i] = 1;
    while(!q.empty()){
        int front = q.front(); 
        q.pop();
        ans.push_back(front);
        set<int> curr = adjlist[front];
        for(auto i : curr){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }

    }
}

vector<int> bfs(int n, vector<pair<int,int>> edges){
    unordered_map<int , set<int>> adjList;
    adjMaker(adjList,edges);
    vector<int> ans;
    unordered_map<int , bool> visited;

    //travesrse all component of a graph
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            bfsTraversal(adjList, visited , ans , i);
        }
    }
}
