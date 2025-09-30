#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        bool pos = false;
        for (int i=0; i<n; i++) {
            cin >> v[i];
            if (!v[i]) pos = true; // if there is at least one zero, this sequence could be valid
        }
        for (int i=1; i<n; i++) if (pos) {
            if (!(v[i] + v[i-1])) pos = false; // for each pair of adjacent elements, check if both are zero, if so, this sequence is invalid
        }
        cout << (pos? "NO": "YES") << endl;
    }
}