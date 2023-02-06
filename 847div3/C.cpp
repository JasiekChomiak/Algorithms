// PROBLEM: https://codeforces.com/contest/1790/problem/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void show(const vector<int>& vs) {
    for (auto v: vs) {
        cout << v << " ";
    }
    cout << "\n";
}

void read(vector<int>& vs) {
    for (auto& v: vs) {
        cin >> v;
    }
}

void solve() {
    int n;
    cin >> n;

    vector <int> a(n-1), b(n-1), c(n-1);
    read(a);
    read(b);
    read(c);

    int first;

    if (a[0] == b[0] == c[0]) {
        first = a[0];
    } else if (a[0] == b[0]) {
        cout << a[0] << " ";
        show(c);
        return;
    } else if (a[0] == c[0]) {
        cout << a[0] << " ";
        show(b);
        return;
    } else {
        cout << b[0] << " ";
        show(a);
        return;
    }


    for (int i = 3; i < n; ++i) {
        read(a);
        if (a[0] != first) {
            cout << first << " ";
            show(a);
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        solve();
    }

    return 0;
}
