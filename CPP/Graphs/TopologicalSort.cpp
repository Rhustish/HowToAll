#include<bits/stdc++.h>
using namespace std;

//  ONLY WORKS FOR DAG - DIRECTED ACYCLIC GRAPHS

// DEFINITION : A LINEAR ORDERING OF THE VERTICES OF A GRAPH SUCH THAT 
//              FOR EVERY EDGE U-V , U ALWAYS APPEARS BEFORE V IN THAT 
//              ORDERING.

//USING DFS

void makeADJ(unordered_map<int , set<int> > &adj , vector<vector<int> > edges){
    for(auto i : edges){
        adj[i[0]].insert(i[1]);
    }
}

void topologicalDFS(unordered_map<int , set<int> > adj , unordered_map<int , bool> &visited , int node , stack<int> &s){
    visited[node] = 1;
    for(auto i : adj[node]){
        if(!visited[i]){
            topologicalDFS(adj,visited,i,s);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int , set<int> > adj;
    stack<int> s;
    vector<int> ans;
    makeADJ(adj,edges);   
    unordered_map<int , bool > visited;
    for(int i = 0 ; i < v ; i ++){
        if(!visited[i]){
            topologicalDFS(adj,visited,i,s);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}