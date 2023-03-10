#include<bits/stdc++.h>

using namespace std;

bool dfs(int node, int color,vector<int> adjList[],vector<int>&colored){
    colored[node] = color;
    
    for(int it : adjList[node]){
        if(colored[it] == -1){
            dfs(it,!color,adjList,colored);
        }else if(colored[it] == color)
        return false;
    }

    return true;
}

int main()
{
    int V, E;
    std::cin >> V >> E;
    std::vector<int> adjList[V + 1];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int>colored(V,-1);
     dfs(1,0,adjList,colored) ? cout<< "biparite" : cout<< "not bipartite";
  
    return 0;
}