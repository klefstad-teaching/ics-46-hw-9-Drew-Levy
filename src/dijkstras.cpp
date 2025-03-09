#include "dijkstras.h"

struct Node {
    int vertex, weight;
    bool operator>(const Node& other) const {return weight > other.weight;}
};

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {

    int n = G.numVertices;
    vector<int> distance(n, INF);
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<bool> visited(n, false);

    distance[source] =0;
    pq.push({source, 0});

    while(!pq.empty()){
        Node current = pq.top();
        pq.pop();
        int u = current.vertex;

        if(visited[u]) continue;
        visited[u] = true;

        for (const Edge& neighbor : G[u]) {
            int v = neighbor.dst;
            int weight = neighbor.weight;
            
            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push({v, distance[v]});
            }
        }
    }
    return distance;
}

vector<int> extract_shortest_path(const vector<int>& distances,const vector<int>& previous, int destination) {
     /* if (destination < 0 ||  static_cast<size_t>(destination) >= distances.size() || distances[destination] == INF) {
        return {}; 
    }*/
    size_t r = distances.size();
    r++;
    vector<int> path;
    for (int v = destination; v != -1; v = previous[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total){
    for(size_t i =0; i  < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << "\nTotal cost is " << total << "\n";
}

