#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void show(const vector<T>& vs) {
    for (auto v: vs) {
        cout << v << " ";
    }
    cout << "\n";
}

void solve() {
    int n;
    cin >> n;

    vector<int> vs(n);
    for (auto& v: vs) {
        cin >> v;
    }

    int start = 0;
    int length = 1;

    cout << length << " ";

    for (int end = 1; end < n; ++end) {
        ++length;
        while (vs[start] < length) {
            ++start;
            --length;
        }

        cout << length << " ";
    }

    cout << "\n";
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
