#include <iostream>
#include <vector>
#include <climits>
#include<bits/stdc++.h>
using namespace std;

class Graph {

public:
    unordered_map<int,vector<pair<int,int>>> adj;
    int N;
    vector<int> result;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    Graph(int n, vector<vector<int>>& edges){
        N=n;
        for(auto &v: edges){
            adj[v[0]].push_back({v[1],v[2]});
        }
    }

    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }

    int shortestPath(int node1, int node2) {
        vector<int> result(N,INT_MAX);
        result[node1]=0;
        pq.push({0,node1});
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for( auto &v:adj[node]){
                int adjn=v.first;
                int dist=v.second;
                if(d+dist<result[adjn]){
                    result[adjn]=d+dist;
                    pq.push({d+dist,adjn});
                }
            }
        }
        return result[node2]==INT_MAX?-1:result[node2];
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
