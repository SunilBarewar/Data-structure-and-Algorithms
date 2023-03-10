#include <bits/stdc++.h>

using namespace std;
bool dfsCheck(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
{
    vis[node] = 1;
    pathVis[node] = 1;

    // traverse for adjacent nodes
    for (auto it : adj[node])
    {
        // when the node is not visited
        if (!vis[it])
        {
            if (dfsCheck(it, adj, vis, pathVis) == true)
            {
                return true;
            }
        }
        // if the node has been previously visited and
        // it is also visited in same path in pathvis array then return true;
        else if (pathVis[node] == 1)
            return true;
    }

    pathVis[node] = 0;
    return false;
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
    }

    vector<int> vis(V+1, 0), pathVis(V+1, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfsCheck(1, adjList, vis, pathVis))
            {
                cout << "cyclic is present";
                break;
            }
        }
    }
    return 0;
}