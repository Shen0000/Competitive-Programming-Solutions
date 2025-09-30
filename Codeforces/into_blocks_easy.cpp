#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    int n, q, ans = 0;
    cin >> n >> q;
    vector<int> v(n);
    map<int, int> first, last;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        if (!first[v[i]]) first[v[i]] = i;
        last[v[i]] = i;
    }
    int index = 0;
    while (index < n) {
        int r = last[v[index]];
        int l = index;
        while (l < r) {
            if (last[v[l]] > r) {
                r = last[v[l]];
            }
            l++;
        }
        set<int> s;
        map<int, int> mp;
        for (int i=index; i<=r; i++) {
            s.insert(v[i]);
            mp[v[i]]++;
        }
        int m=0;
        for (int x: s) m = max(m, mp[x]);
        ans += (r - index + 1) - m;
        index = r + 1;
    }
    cout << ans << endl;
}