#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    vector<ll> ans;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> h(n), a(n), t(n);
        map<int, int> mp;
        for (int i=0; i<n; i++) {
            cin >> h[i];
        }
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        for (int i=0; i<n; i++) {
            cin >> t[i];
            mp[t[i]] = i;
        }
        ll min_days = 0;
        bool pos = true;
        for (int i=0; i<n-1; i++) {
            int i1 = mp[i];
            int i2 = mp[i+1];
            if (h[i1] > h[i2]) continue;
            else {
                if (a[i1] <= a[i2]) {
                    pos = false;
                    break;
                }
                else {
                    ll diff = h[i2] - h[i1];
                    ll days = (diff) / (a[i1] - a[i2]) + 1;
                    min_days = max(min_days, days);
                }
            }
        }
        if (!pos) {
            // cout << -1 << endl;
            ans.push_back(-1);
        }
        else {
            // cout << min_days << endl;
            ans.push_back(min_days);
        }
    }
    for (int x: ans) {
        cout << x << endl;
    }
}