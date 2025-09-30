#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<char> > v(n);
        string s;
        for (int i=0; i<n; i++) {
            cin >> s;
            for (int j=0; j<m; j++) {
                v[i].push_back(s[j]);
            }
        }
        int r = 0, c = 0;
        int curr = 0;
        for (int i=0; i<n; i++) { // find bad rows
            curr = 0;
            for (int j=0; j<m; j++) {
                curr += v[i][j] - '0';
            }
            if (curr % 2) r++;
        }
        for (int j=0; j<m; j++) { // find bad columns
            curr = 0;
            for (int i=0; i<n; i++) {
                curr += v[i][j] - '0';
            }
            if (curr % 2) c++;
        }
        cout << max(r, c) << endl; // take max of rows and columns
    }
}