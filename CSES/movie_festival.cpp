#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int a, b;
    cin >> n;
    vector<pair<int, int> > v(n);
    for (auto &x: v) {
        cin >> x.second >> x.first;
    }
    sort(v.begin(), v.end());
    int ans = 0, curr = 0;
    for (auto x: v) {
        if (x.second >= curr) {
            ans++;
            curr = x.first;
        }
    }
    cout << ans << endl;
}