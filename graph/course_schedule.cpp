#include <bits/stdc++.h>

using namespace std;

class Solution
{
    bool topo_sort_bfs(vector<int> adj[], int V)
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
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        return cnt != V;
    }

public:
    bool isPossible(int N, vector<pair<int, int>> &courses)
    {
        vector<int> adj[N];
        for (auto it : courses)
        {
            adj[it.first].push_back(it.second);
        }
        return topo_sort_bfs(adj, N);
    }
};

int main()
{
    int N, E;
    vector<pair<int, int>> courses;

    cin >> N >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        courses.push_back({u, v});
    }

    Solution obj;
    if (obj.isPossible(N, courses))
    {
        cout << "Yes";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}