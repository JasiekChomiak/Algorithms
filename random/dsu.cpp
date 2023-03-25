// The Disjoint Set Union is a data structure representing nodes
// from 1 to N (or 0 to N-1) that allows the following operations:
//   * find(v)    -> return the "representative" of the set
//                   that contains the node v
//
//   * union(u,v) -> join the sets that contain the nodes
//                   u and v
//
// This structure is very useful in many algorithmic tasks.
// The idea is very simple:
//   - we start with N separate sets
//   - each node has its parent (initially itself) and a rank
//   - whenever we find the representative of some vertex
//     we "compress" the path that leads from that vertex
//     to the representative, meaning we set the representative
//     as the direct parent of every node along this path
//   - when we join two sets together we join the "smaller"
//     set to "bigger" one and update their sizes accordingly
//
// Both the find and join operation have *basically* constant time complexities.
// Read more here: https://en.wikipedia.org/wiki/Disjoint-set_data_structure

#include <iostream>
#include <vector>

using namespace std;

struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        rank = vector<int>{n};
        parent = vector<int>{n};
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        int root = x;
        while (parent[root] != root) {
            root = parent[root];
        }

        // path compression
        while (parent[x] != root) {
            int p = parent[x];
            parent[x] = root;
            x = p;
        }

        return root;
    }

    // normally the function is called "union", but it's a keywoard in C++
    void join(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) {
            return;
        }

        // we want rank[x] >= rank[y]
        if (rank[x] < rank[y]) {
            swap(x, y);
        }

        // join the set with lower rank to the one with higher rank
        parent[y] = x;

        // if both sets had the same rank, increase rank of x
        if (rank[x] == rank[y]) {
            ++rank[x];
        }
    }

    bool isSameSet(int x, int y) {
        return (find(x) == find(y));
    }
};

// Example of use
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 6;

    // create a disjoint-set family with 6 elements 0...5
    auto dsu = DSU(N);

    for (int i = 0; i < N; ++i) {
        cout << dsu.find(i) << "\n"; // the parent of i is i to begin with
    }

    // we join 0 with 1 and 2 with 3 giving us {0,1} {2,3} {4} {5}
    dsu.join(0, 1);
    dsu.join(2, 3);

    cout << dsu.isSameSet(0, 1) << "\n"; // true
    cout << dsu.isSameSet(0, 2) << "\n"; // false

    // now if we join 0 with 3 we get {0,1,2,3} {4} {5}
    dsu.join(0,3);

    cout << dsu.isSameSet(0, 3) << "\n"; // true
    cout << dsu.isSameSet(0, 4) << "\n"; // false

    for (int i = 0; i < N; ++i) {
        cout << dsu.find(i) << "\n"; // values 0..3 will have the same parent
    }

}

