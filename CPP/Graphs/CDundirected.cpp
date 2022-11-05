#include "bfs.cpp"
#include "dfs.cpp"

// Cycle detection using bfs traversal
bool isCyclicBFS(int i , unordered_map<int , bool > &visited , unordered_map<int , set<int> > adjList){
    unordered_map<int , int > parent;
    parent[i] = -1;
    visited[i] = 1;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(auto j : adjList[f]){
            if(visited[j] == 1 && j != parent[f] ){
                return 1;
            }else if(!visited[j]){
                q.push(j); 
                visited[j] =  1;
                parent[j] = f;
            }
        }
    }
    return 0;
}

// Cycle detection using dfs traversal



bool isCyclicDFS(int i , unordered_map<int,bool> &visited , unordered_map<int , set<int> > &adjList , int currParent){
    visited[i] = 1;
    for(auto j : adjList[i]){
        if(!visited[j]){
            visited[j] = 1;
            bool cycleDetected = isCyclicDFS(j , visited , adjList , i);
            if(cycleDetected) return 1;
        }
        else if(visited[j] && j != currParent){
            return 1;
        }
    }
    return 0;
}







string cycleDetection(vector<vector<int>> &edges , int n , int m){
    unordered_map<int , set<int> > adjList;
    createAdjList(adjList,edges);
    unordered_map<int,bool> visited;

    for(int i  = 0 ; i < n ; i++){
        if(!visited[i]){
            bool ans = isCyclicDFS(i,visited,adjList,-1);
            if(ans)return "Yes";
        }
    }
    return "No";
}




