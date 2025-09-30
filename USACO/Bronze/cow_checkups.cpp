#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int patients;
    cin >> n;
    vector<int> a(n), b(n), ans(n+1);
    vector<int> presum(n+1);
    vector<vector<int> > mem(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
        presum[i+1] = presum[i];
        if (b[i] == a[i]) presum[i+1]++;
    }
    for (int j=0; j<n; j++) {
        for (int i=0; i+j < n; i++) { // iterate through swaps by increasing size, saving previous calculations in array to speed up computation
            if (j == 0) {
                mem[i][i] = (a[i] == b[i])? 1: 0;
                patients = presum[n] - presum[i+1] + presum[i] + mem[i][i];
                ans[patients]++;
            }
            else if (j == 1) {
                patients = presum[n] - presum[i+j+1] + presum[i];
                if (a[i] == b[i+j]) mem[i][i+j]++;
                if (a[i+j] == b[i]) mem[i][i+j]++;
                patients += mem[i][i+j];
                ans[patients]++;
            }
            else {
                patients = presum[n] - presum[i+j+1] + presum[i];
                mem[i][i+j] = mem[i+1][i+j-1];
                if (a[i] == b[i+j]) mem[i][i+j]++;
                if (a[i+j] == b[i]) mem[i][i+j]++;
                patients += mem[i][i+j];
                ans[patients]++;
            }
        }
    }
    for (int i=0; i<n+1; i++) {
        cout << ans[i] << endl;
    }
}