/*
 * The Ford-Fulkerson algorithm is used to find the maximum flow in a network.
 * Read more here: https://en.wikipedia.org/wiki/Ford%E2%80%93Fulkerson_algorithm
 * It's a greedy algorithm that tries to find any path from the source to the sink
 * over which some flow is allowed and adds it to the total flow.
 * Time complexity: O(E * f), where E is the number of edges and f is the maximum flow value.
 */
#include <iostream>
#include <vector>
#include <hash_map>
using namespace std;

// A definition of pair hashing
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }

        return hash1;
    }
};

// Auxiliary types
typedef unordered_map<int, unordered_map<int, int>> edges;
typedef unordered_map<pair<int, int>, int, hash_pair> flow;

struct Graph {
    int source, sink, size;
    edges E;

    Graph(int source, int sink, int size) {
        this->source = source;
        this->sink = sink;
        this->size = size;
        this->E = edges{};
    }

    void addEdge(int u, int v, int capacity) {
        if (E.find(u) == E.end()) {
            E[u] = unordered_map<int, int>{};
        }

        E[u][v] = capacity;
    }
};

// findFlow looks for a flow starting at node and finishing in the sink.
// It sets the previous vector to allow reconstructing of the flow.
void findFlow(int node, int prev, vector<int>& previous, flow& _flow, const Graph& G) {
    previous[node] = prev;

    // if we are at the sink we found a flow
    if (node == G.sink) {
        return;
    }

    // check if node has any neighbours
    if (G.E.find(node) == G.E.end()) {
        return;
    }

    // if so iterate over them and check if there is any flow left between node and each neighbour
    for (auto e: G.E.at(node)) {
        int v = e.first;
        int c = e.second;

        int f = _flow[pair<int, int>(node, v)];

        // if the neighbour was not visited and there is still flow left, we do a recursive call
        if (previous[v] == -1 && f < c) {
            findFlow(v, node, previous, _flow, G);
        }
    }
}

// updateFlow takes the flow (the previous vector) counts its minimum and updated the flow
int updateFlow(vector <int>& previous, flow& _flow, const Graph& G) {
    // find the minimum over the path we found
    int minFlow = 1000000001;
    int v = G.sink;
    while (v != G.source) {
        int u = previous[v];
        // the edge in the flow path goes from u to v (u -> v)
        int leftFlow = G.E.at(u).at(v) - _flow[pair<int, int>(u,v)];
        minFlow = min(minFlow, leftFlow);
        v = u;
    }

    // update the values along the path
    v = G.sink;
    while (v != G.source) {
        int u = previous[v];
        _flow[pair<int,int>(u,v)] += minFlow;
        _flow[pair<int,int>(v,u)] -= minFlow;
        v = u;
    }

    return minFlow;
}

int fordfulkerson(const Graph& G) {
    flow _flow;
    int totalFlow = 0;

    // loop until no new path can be found from source to sink
    while(true) {
        vector<int> previous(G.size, -1);
        findFlow(G.source, G.source, previous, _flow, G);

        if (previous[G.sink] == -1) {
            break;
        }

        int flowValue = updateFlow(previous, _flow, G);
        totalFlow += flowValue;
    }

    return totalFlow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Graph G(0, 5, 6);
    G.addEdge(0, 1, 4);
    G.addEdge(0, 2, 2);
    G.addEdge(1, 2, 1);
    G.addEdge(1, 3, 2);
    G.addEdge(2, 3, 1);
    G.addEdge(2, 4, 2);
    G.addEdge(3, 5, 7);
    G.addEdge(4, 5, 3);

    int maxFlow = fordfulkerson(G);

    cout << maxFlow << "\n";

    return 0;
}