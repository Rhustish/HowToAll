#include "CDundirected.cpp"

void directedADJMaker(unordered_map<int , set<int> > &adj , vector<pair<int , int > > edges){
    for(int i = 0 ; i < edges.size() ; i++){
        adj[edges[i].first].insert(edges[i].second);
    }
}

//ALGO: we will make another visted data struct which will keep track of the nodes traversed in the current path.
//      if, while iterating, we come to such a node which calls to the next node, but the next node has already been
//      in the current path i.e. DFSvisited[i] = 1, then the graph is cyclic

bool isCyclicDDFS(unordered_map<int , set<int> > &adj , unordered_map<int , bool > &visited , int node, unordered_map<int , bool> DFSvisited){
    visited[node]=1;
    DFSvisited[node] = 1;

    for(auto i : adj[node]){
        if(!visited[i]){
            bool ans = isCyclicDDFS(adj,visited,i,DFSvisited);
            if(ans) return 1;
        }else if(DFSvisited[i]){
            return 1;
        }
    }
    DFSvisited[node]=0;
    return 0;
}

int detectCycleInDirectedGraph(int n , vector <pair < int , int > > &edges){
    unordered_map<int , set<int> > adj;
    directedADJMaker(adj,edges);

    unordered_map<int , bool> visited , DFSvisited;

    for(int i = 1 ; i <= n ; i++){
        if(!visited[i]){
            bool ans = isCyclicDDFS(adj,visited,i,DFSvisited);
            if(ans) return 1;
        }
    }
    return 0;
}