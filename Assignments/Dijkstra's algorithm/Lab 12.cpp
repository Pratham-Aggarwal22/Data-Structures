#include <iostream>
#include <climits>

using namespace std;

void dijkstra(int G[100][100], int V, int s) {
    int distance_list[100];
    bool tracking_list[100];

    // Initialization
    for (int i = 0; i < V; i++) {
        distance_list[i] = INT_MAX;
        tracking_list[i] = false;
    }

    distance_list[s] = 0;

    // Dijkstra's algorithm
    for (int count = 0; count < V - 1; count++) {
        int min_distance = INT_MAX, min_index;

        // Find the minimum distance vertex
        for (int v = 0; v < V; v++) {
            if (!tracking_list[v] && distance_list[v] <= min_distance) {
                min_distance = distance_list[v];
                min_index = v;
            }
        }

        // Mark the selected vertex as visited
        tracking_list[min_index] = true;

        // Update distance value of the adjacent vertices
        for (int u = 0; u < V; u++) {
            if (!tracking_list[u] && G[min_index][u] && distance_list[min_index] != INT_MAX
                && distance_list[min_index] + G[min_index][u] < distance_list[u]) {
                distance_list[u] = distance_list[min_index] + G[min_index][u];
            }
        }
    }

    // Print the shortest distance from source to rest of the vertices
    cout << "Vertex\t\tDistance from source vertex" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << distance_list[i] << endl;
    }
}

int main() {
    int V, s;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int G[100][100];

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> G[i][j];
        }
    }

    cout << "Enter the source vertex: ";
    cin >> s;

    cout << "\n";
    dijkstra(G, V, s);

    return 0;
}
