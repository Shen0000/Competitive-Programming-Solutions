#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n), presum(n + 1);
    for (int &x: v) cin >> x;
    presum[0] = 0;
    for (int i=0; i<n; i++) {
        presum[i + 1] = v[i] + presum[i];
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            int sum = presum[j+1] - presum[i];
            double average = double(sum) / (j-i+1);
            bool match = false;
            for (int k=i; k<=j; k++) {
                if (double(v[k]) == average) {
                    match = true;
                    break;
                }
            }
            ans += (match? 1 : 0);
        }
    }
    cout << ans << endl;
}