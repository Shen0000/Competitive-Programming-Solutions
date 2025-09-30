#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long px, py, qx, qy; // take in input
        cin >> n >> px >> py >> qx >> qy; // ""
        vector<long long> v(n);
        long long sum = 0, m = 0;
        for (long long &x: v) {
            cin >> x;
            m = max(m, 1ll*x); // concurrently calculate the max length in the array
            sum += x; // concurrently calculate the running sum
        }
        long long max_distance, min_distance; // use squaring distance method to get around using floats
        max_distance = sum * sum; 
        min_distance = max(0ll, 2 * m - sum) * max(0ll, 2 * m - sum);
        long long distance = (qx - px) * (qx - px) + (qy - py) * (qy - py);
        cout << (distance <= max_distance && distance >= min_distance ? "YES": "NO") << endl; // if distance is between interval, then it's possible, otherwise impossible
    }
}