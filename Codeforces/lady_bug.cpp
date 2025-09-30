#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        int za = 0, zb = 0;
        for (int i=0; i<n; i++) {
            if (i%2 == 0) {
                if (a[i] == '0') za++;
                if (b[i] == '0') zb++;
            }
            else {
                if (a[i] == '0') zb++;
                if (b[i] == '0') za++;
            }
        }
        cout << ((za >= (n+1)/2 && zb >= n/2)? "YES": "NO") << endl;
    }
}