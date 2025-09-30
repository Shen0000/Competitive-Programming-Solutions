#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        if (b < a && !(a - b == 1 && a % 2)) {
            cout << -1 << endl;
        }
        else if (a - b == 1 && a % 2) {
            cout << y << endl;
        }
        else {
            int d = b - a ;
            long long ans = 0;
            ans += d / 2 * min(2*x, x + y);
            if (d % 2) {
                if (!(a % 2)) {
                    ans += min(x, y);
                }
                else {
                    ans += x;
                }
            }
            cout << ans << endl;
        }
    }
}