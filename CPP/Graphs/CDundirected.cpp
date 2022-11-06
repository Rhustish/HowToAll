#include "bfs.cpp"
#include "dfs.cpp"

// Cycle detection using bfs traversal

//ALGO : we define a new map which stores info as "child" -> "parent" 
//       if a recurring node (i.e. node's visited = true) is found in the adj list of the current node and
//       that node isn't the parent of the current node, then the graph is sure to be cyclic in nature.

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
//ALGO: Similar logic as BFS but instead of making a whole data structur to store the parents we will just
//      check if the next node is recurring... if it is so, and it is not the parent of the current node 
//      the the graph is defo cyclic


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




