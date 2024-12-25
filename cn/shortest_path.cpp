#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distTo(V, INT_MAX);
        
        distTo[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for (auto it : adj[node])
            {
                int v = it[0];
                int w = it[1];
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
                    pq.push({distTo[v], v});
                }
            }
        }
        return distTo;
    }
};

int main()
{
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj[V];

    cout << "Enter the edges (format: from_vertex to_vertex weight):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // Add edge from u to v with weight w
        adj[v].push_back({u, w}); // If the graph is undirected, add the reverse edge
    }

    int S; // Starting vertex
    cout << "Enter the starting vertex: ";
    cin >> S;

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    cout << "Shortest distances from vertex " << S << ":" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << "Distance to vertex " << i << ": " << res[i] << endl;
    }

    return 0;
}