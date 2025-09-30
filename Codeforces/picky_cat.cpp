#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
            v[i] = abs(v[i]);
        }
        int x = v[0];
        sort(v.begin(), v.end());
        int index = -1;
        for (int i=0; i<n; i++) if (v[i] == x) {
            index = i;
            break;
        }
        cout << (index <= n/2? "YES": "NO") << endl;
    }
}