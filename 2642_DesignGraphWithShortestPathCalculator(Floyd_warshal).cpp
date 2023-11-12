#include <iostream>
#include <vector>
#include <climits>

class Graph {
public:
    vector<vector<int>> adj;
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        adj = vector<vector<int>>(n, vector<int>(n, 1e9));
        
        for(auto &vec : edges) {
            int u    = vec[0];
            int v    = vec[1];
            int cost = vec[2];
            
            adj[u][v] = cost;
        }
        
        for(int i = 0; i<n; i++) {
            adj[i][i] = 0;
        }
        
        //Floyd Warshal
        for(int k = 0; k<n; k++) {
            
            for(int i = 0; i<N; i++) {
                for(int j = 0; j<N; j++) {
                    
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                        
                }
            }
            
        }
    }
    
    void addEdge(vector<int> edge) {
        int u    = edge[0];
        int v    = edge[1];
        int cost = edge[2];
        //check with 2 new vertices - u and v
        
        for(int i = 0; i<N; i++) {
            for(int j = 0; j<N; j++) {

                adj[i][j] = min(adj[i][j], adj[i][u] + cost + adj[v][j]);

            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return adj[node1][node2] == 1e9 ? -1 : adj[node1][node2];
    }
};

int main() {
    // Example usage:
    int n = 4;  // Number of nodes
    std::vector<std::vector<int>> edges = {{0, 1, 2}, {0, 2, 4}, {1, 2, 1}, {2, 3, 3}};

    Graph graph(n, edges);

    // Adding an edge after initializing the graph
    std::vector<int> newEdge = {1, 3, 5};
    graph.addEdge(newEdge);

    // Finding the shortest path between nodes 0 and 3
    int shortest = graph.shortestPath(0, 3);

    if (shortest == -1) {
        std::cout << "There is no path between the nodes." << std::endl;
    } else {
        std::cout << "Shortest path between nodes 0 and 3: " << shortest << std::endl;
    }

    return 0;
}
