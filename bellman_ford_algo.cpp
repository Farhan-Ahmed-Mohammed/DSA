#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000000;  // Large number representing "infinity"

vector<int> bellmanFord(int n, int m, int src, vector<vector<int>>& edges) {
    vector<int> dist(n + 1, INF);  // Initialize all distances to INF
    dist[src] = 0;  // Distance to source is 0

    // Relax all edges (n-1) times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];  // Start vertex
            int v = edges[j][1];  // End vertex
            int wt = edges[j][2]; // Edge weight

            // Relaxation step
            if (dist[u] != INF && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // After running the algorithm, return the distance array
    return dist;
}

int main() {
    // Reading the number of vertices (n), edges (m), and the source vertex (src)
    int n, m, src;
    cin >> n >> m >> src;

    vector<vector<int>> edges(m, vector<int>(3));

    // Reading the edges: u, v, w (start vertex, end vertex, weight)
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    // Call Bellman-Ford algorithm
    vector<int> dist = bellmanFord(n, m, src, edges);

    // Output shortest distances
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << "1000000000 ";  // If vertex is unreachable, print 1000000000
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
