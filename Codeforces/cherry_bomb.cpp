#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, ans = 0;
        int mn = 1e9, ma = -1;
        cin >> n >> k;
        vector<int> a(n), b(n);
        vector< pair<int, int> > v(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            v[i].first = a[i];
            mn = min(mn, a[i]);
            ma = max(ma, a[i]);
        }
        for (int i=0; i<n; i++) {
            cin >> b[i];
            v[i].second = b[i];
        }
        sort(v.begin(), v.end(), cmp);
        if (v[0].second == -1) {
            ans = max(0, (k + mn) - ma + 1);
        }
        else {
            for (int i=1; i<n; i++) {
                if (v[i].second == -1 && (v[i].first > v[0].first + v[0].second || v[i].first + k < v[0].first + v[0].second)) {
                    ans--;
                    break;
                }
                if (v[i].second != -1 && v[i].first + v[i].second != v[i-1].first + v[i-1].second) {
                    ans--;
                    break;
                }
            }
            ans++;
        }
        cout << ans << endl;
    }
}