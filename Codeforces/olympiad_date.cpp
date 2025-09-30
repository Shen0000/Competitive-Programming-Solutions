// https://codeforces.com/contest/2091/problem/A
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

bool sufficient(map<int, int> mp) {
    return mp[0] >= 3 && mp[1] >= 1 && mp[2] >= 2 && mp[3] >= 1 && mp[5] >= 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> mp;
        int ans=0;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        for (int i=0; i<n; i++) {
            mp[v[i]]++;
            if (sufficient(mp)) {
                ans = i + 1;
                break;
            }
        }
        cout << ans << endl;
    }
}