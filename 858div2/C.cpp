// PROBLEM: https://codeforces.com/contest/1806/problem/C
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

template <typename T>
void show(const vector<T>& vs) {
    for (auto &v: vs) {
        cout << v << " ";
    }

    cout << "\n";
}

template <typename T>
void load(vector<T>& vs) {
    for (auto &v: vs) {
        cin >> v;
    }
}

long long distance(vector <int>& p, vector <int>& q) {
    long long d = 0;
    for (int i = 0; i < p.size(); ++i) {
        d += abs(p[i] - q[i]);
    }

    return d;
}

void solve() {
    int n;
    cin >> n;

    vector <int> vs(2*n);
    load(vs);

    long long sum = 0;
    for (auto v: vs) {
        sum += abs(v);
    }

    sort(vs.begin(), vs.end());

    if (n == 1) { // [a,a]
        cout << vs[1] - vs[0] << "\n";
    } else if (n == 2) { // [0,0,0,0] or [-1,-1,-1,2] or [2,2,2,2]
        vector <int> v2{-1,-1,-1,2};
        long long d2 = distance(vs, v2);

        vector<int> v3{2,2,2,2};
        long long d3 = distance(vs, v3);

        cout << min(sum, min(d2, d3)) << "\n";
    } else if (n % 2 == 1) {
        cout << sum << "\n";
    } else {
        vector <int> v(2 * n, -1);
        v[2 * n - 1] = n;
        long long d = distance(vs, v);

        cout << min(sum, d) << "\n";
    }
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        solve();
    }
    return 0;
}
