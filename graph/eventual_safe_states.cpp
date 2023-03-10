#include <bits/stdc++.h>

using namespace std;

class Solution
{
    bool dfsCheck(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis, vector<int> &check)
    {
        vis[node] = 1;
        pathVis[node] = 1;

        // traverse for adjacent nodes
        for (auto it : adj[node])
        {
            // when the node is not visited
            if (!vis[it])
            {
                if (dfsCheck(it, adj, vis, pathVis, check) == true)
                {
                    return true;
                }
            }
            // if the node has been previously visited and
            // it is also visited in same path in pathvis array then return true;
            else if (pathVis[node] == 1)
                return true;
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }


vector<int> topo_approach(int V, vector<int> adj[]){
    //creating reversed adjancecy list
    vector<int>revAdj[V];
    int indegree[V] =  {0};
    for(int i = 0;i < V;i++){
        for(auto node : adj[i]){
            revAdj[node].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    for(int i = 0;i < V;i++){
        if(indegree[i] == 0)q.push(i);
    }
    vector<int>safeNodes;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);

        for(auto it : revAdj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
 
    sort(safeNodes.begin(),safeNodes.end());
    return safeNodes;
}
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> vis(V + 1, 0), pathVis(V + 1, 0), check(V + 1, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfsCheck(1, adj, vis, pathVis, check);
            }
        }

        vector<int> safeNodes;
        for (int i = 0; i <= V; i++)
        {
            if (check[i])
                safeNodes.push_back(i);
        }
        return safeNodes;
    }
};
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
    Solution obj;
    vector<int> safeNodes = obj.eventualSafeNodes(V, adjList);

    for (int i = 0; i < safeNodes.size(); i++)
    {
        cout << safeNodes[i] << " ";
    }

    return 0;
}