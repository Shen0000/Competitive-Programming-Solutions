#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > cols(m, vector<int>(n, 0));
        vector<long long> col_sum(m);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> cols[j][i];
                col_sum[j] += 1ll * cols[j][i];
            }
        }
        long long res = 0;
        long long curr;
        for (int i=0; i<m; i++) {
            sort(cols[i].begin(), cols[i].end());
            curr = col_sum[i];
            for (int j=0; j<n; j++) {
                curr -= cols[i][j];
                res += 1ll * curr - (n - j - 1) * 1ll * cols[i][j];
            }
        }

        cout << res << endl;
    }
}