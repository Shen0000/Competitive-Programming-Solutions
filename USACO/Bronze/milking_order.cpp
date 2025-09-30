#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <cstdio>

using namespace std;

bool check(vector<int> v, vector<int> ord, set<int> s) {
    int n = v.size();
    int index = ord.size() - 1;
    for (int i=n-1; i>=0; i--) {
        if (s.count(v[i])) {
            while (ord[index] != v[i]) index--;
            continue;
        }
        while (1) {
            if (index < 0) return false;
            if (ord[index]) {
                index--;
                continue;
            }
            ord[index] = v[i];
            index--;
            break;
        }
    }
    return true;
}

int main() {
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    int n, m, k, a, b;
    cin >> n >> m >> k;
    // cout << n << " " << m << " " << k << endl;
    vector<int> v(m), ord(n, 0);
    set<int> s;
    s.insert(1);
    for (int &x: v) cin >> x;
    bool flag = false;
    int win = -1;
    for (int i=0; i<k; i++) {
        cin >> a >> b;
        ord[b-1] = a;
        s.insert(a);
        if (a == 1) {
            flag = true;
            win = b;
        }
    }
    if (flag) {
        cout << win << endl;
        return 0;
    }
    for (int i=0; i<n; i++) if (!ord[i]) {
        ord[i] = 1;
        bool pos = check(v, ord, s);
        if (pos) {
            cout << i + 1 << endl;
            break;
        }
        ord[i]--;
    }
    return 0;
}