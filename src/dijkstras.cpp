#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {

    //int n = G.numVertices;
    vector<int> distance(G.numVertices, INF);
    vector<bool> visited(G.numVertices, false);
    previous.resize(G.numVertices, -1);

    distance[source] =0;
    previous[source] = -1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visited[u]) continue;
        visited[u] = true;

        for (Edge edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;
            
            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push({distance[v], v});
            }
        }
    }
    return distance;
}

vector<int> extract_shortest_path(const vector<int>& distances,const vector<int>& previous, int destination) {
      if (destination < 0 ||  static_cast<size_t>(destination) >= distances.size() || distances[destination] == INF) {
        return {}; 
    }
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
    cout << endl;
    cout  << "Total cost is " << total << endl;
}

