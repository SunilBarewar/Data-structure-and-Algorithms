#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<int> topo_sort_dfs(int node, vector<pair<int, int>> adj[], stack<int> &st, vector<int> &vis)
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            int v = it.first;
            if (!vis[v])
                topo_sort_dfs(v, adj, st, vis);
        }

        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        // find topo sort
        stack<int> st;
        vector<int> vis(N, 0);
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                topo_sort_dfs(i, adj, st, vis);
            }
        }

        // step 2 : do the distance thing

        vector<int> dist(N, 1e9);
        dist[0] = 0;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            for (auto it : adj[node])
            {

                int v = it.first;
                int wt = it.second;
                if (dist[node] + wt < dist[v])
                {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        return dist;
    }
};
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

    return 0;
}