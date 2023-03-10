#include <iostream>
#include <vector>
#include <queue>
 void BFS(int stNode, std::vector<int>adj[],int V)
{
    // traverse a graph level wise
    // breadth first search
    std:: queue<int> q;
    std:: vector<bool>vis(V+1);
    q.push(stNode);
    vis[stNode] = true;                       
    while(!q.empty()){
        int node = q.front();
        q.pop();
        std::cout<<node<<" ";
        for(int it : adj[node]){
            if(!vis[it])
            {
                vis[it]  = true;
                q.push(it);
            }
        }

    }

}
// multidimenstional bfs

/*
    // Four directional bfs
        direction formats
        dir = {{0,1},{0,-1},{1,0},{-1,0}}
        dir = [0,-1,0,1,0]

    // eightDirectional bfs
    dir = {{0,1},{0,-1},{1,0},{-1,0},{-1,1},{1,-1},{-1,-1},{1,1}}

    for(i = -1; i<= 1; i++){
        for(int j = -1;j <= 1;j++){
            // it will produce all the above eight combinations
        }
    }
*/
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
    BFS(1,adjList,V);
    return 0;
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


output : 
1 2 6 3 4 7 8 5
*/