#include <bits/stdc++.h>

using namespace std;

vector<int> topo_sort_bfs(vector<vector<int>> &adj, int V)
{
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
        }
    }
    return topo;
}

int main()
{
    int V, E;
    std::cin >> V >> E;
    std::vector<vector<int>> adj(V + 1);

    for (int i = 0; i < E; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> res = topo_sort_bfs(adj,V);
    for(auto node : res)
    cout<< node<<" ";
    return 0;
}