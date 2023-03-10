#include <iostream>
#include <vector>


void dfs(int V, std:: vector<int>adj[],std::vector<bool>&vis){
    if(vis[V])return;
    vis[V]  = true;

    for(auto it : adj[V]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
}

int numberOfConnectedComponents(std::vector<int> adj[], int V, int E)
{
    std::vector<bool>vis(V+1,false);
    int cnt  =  0;
    for(int i = 1;i <= V ; i++){
        if(!vis[i]){
            dfs(i,adj,vis);
            cnt++;
        }
    }
    return cnt;
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
    std:: cout<< numberOfConnectedComponents(adjList,V,E);
}


/*
example :

10 8
1 2
1 3
2 4
3 4
5 6
5 7
6 7
8 9

expected output : 4
*/