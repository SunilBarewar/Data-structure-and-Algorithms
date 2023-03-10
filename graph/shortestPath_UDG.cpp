#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>> adj(N);

        for(int i = 0;i < M;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }


        queue<pair<int,int>> q;
        q.push({src,0});
        vector<int>dist(N,INT_MAX);
        dist[src] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();


            for(int adjNode : adj[node]){
                if(dist[node] + 1 < dist[adjNode]){
                    dist[adjNode] = dist[node] + 1;
                    q.push({adjNode,dist[adjNode]});
                }
            } 
        }
        for(int i = 0;i < N;i++){
            if(dist[i] == INT_MAX)dist[i] = -1;
        }
        return dist;
    }
};

int main()
{
   int V, E;
    std::cin >> V >> E;
    std::vector<vector<int>> edges(E, vector<int>(2));

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj;

    vector<int> ans = obj.shortestPath(edges,V,E,0);

    for (auto it : ans)
        cout << it << " ";

    return 0;
    
  
    return 0;
}