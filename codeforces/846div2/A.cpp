#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

template <typename T>
void show(const vector<T>& vs) {
    for (auto& v: vs) {
        cout << v << " ";
    }

    cout << "\n";
}

template <typename T>
void load(vector <T>& vs) {
    for (auto& v: vs) {
        cin >> v;
    }
}

void solve() {
    int n;
    cin >> n;

    vector <int> vs(n);
    load(vs);

    int e1 = -1, e2 = -1, o1 = -1, o2 = -1, o3 = -1;

    for (int i = 0; i < n; ++i) {
        if (vs[i] % 2 == 0) {
            if (e1 == -1) {
                e1 = i + 1;
            } else {
                e2 = i + 1;
            }
        } else {
            if (o1 == -1) {
                o1 = i + 1;
            } else if (o2 == -1) {
                o2 = i + 1;
            } else {
                o3 = i + 1;
            }
        }
    }

    // even, even, odd
    if (e1 > 0 && e2 > 0 && o1 > 0) {
        cout << "YES\n";
        cout << e1 << " " << e2 << " " << o1 << "\n";
    } else if (o1 > 0 && o2 > 0 && o3 > 0) { // odd x3
        cout << "YES\n";
        cout << o1 << " " << o2 << " " << o3 << "\n";
    } else {
        cout << "NO\n";
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
