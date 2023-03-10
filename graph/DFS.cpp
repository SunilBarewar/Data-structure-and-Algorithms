#include <bits/stdc++.h>

void DFS(int node, std::vector<int> adj[], std::vector<bool> &vis)
{
    if (vis[node])
        return;
    vis[node] = true;
    std::cout << node << " ";
    for (int it : adj[node])
    {
        if (!vis[it])
        {
            DFS(it, adj, vis);
        }
    }
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
    std::vector<bool> vis(V+1);
    DFS(1,adjList,vis);
}
/*
8 8
1 2
1 6
2 3
2 4
6 7
6 8
4 5
7 5


output : 1 2 3 4 5 7 6 8

*/
