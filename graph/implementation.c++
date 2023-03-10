#include<iostream>
#include<vector>

// using namespace std;
int main(){
    int V, E;

    std::cin >> V >> E;


    // adjacency matrix
    int adjMatrix[V+1][V+1];
    for(int i = 0; i < E;i++){
        int u,v;
        std:: cin>> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
        // for a directed graph with an edge pointing from u
        // to v, we just assign adj[u][v] as 1

    }


    // adjacency List

    std::vector<int> adjList[V+1];

    for(int i = 0;i < E;i++){
        int u,v;
        std:: cin>> u>> v;
        adjList[u].push_back(v);    
        adjList[v].push_back(u);    
    }

}