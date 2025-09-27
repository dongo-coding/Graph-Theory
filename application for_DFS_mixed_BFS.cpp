#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
    int u, v, V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    bool BFS(int start, int goal, vector<int>& path) {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == goal) break;
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        if (!visited[goal]) return false;

        for (int v = goal; v != -1; v = parent[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        return true;
    }


    void DFS(int u, vector<bool>& visited, vector<int>& vertices, vector<pair<int, int>>& edges) {
        visited[u] = true;
        vertices.push_back(u);
        for (int v : adj[u]) {
            if (u < v) edges.push_back({ u, v });
            if (!visited[v]) DFS(v, visited, vertices, edges);
        }
    }

    void connectedComponents() {
        vector<bool> visited(V, false);
        int comp = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                vector<int> vertices;
                vector<pair<int, int>> edges;
                DFS(i, visited, vertices, edges);

                cout << "Component " << ++comp << ":\n";
                cout << "  Vertices: ";
                for (int v : vertices) cout << v << " ";
                cout << "\n  Edges: ";
                for (pair<int, int> edge : edges) {
                    int u = edge.first;
                    int v = edge.second;

                } cout << "(" << u << "," << v << ") ";
                cout << "\n";
            }
        }

        if (comp == 1) cout << "Graph is connected.\n";
        else cout << "Graph has " << comp << " connected components.\n";
    }
};

int main() {

    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "\nConnected Components:\n";
    g.connectedComponents();

    int start, goal;
    cout << "\nEnter two vertices to find path: ";
    cin >> start >> goal;

    vector<int> path;
    if (g.BFS(start, goal, path)) {
        cout << "Path from " << start << " to " << goal << ": ";
        for (int v : path) cout << v << " ";
        cout << "\n";
    }
    else {
        cout << "No path exists between " << start << " and " << goal << ".\n";
    }

    return 0;
}

