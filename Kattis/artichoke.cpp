#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double price(double p, double a, double b, double c, double d, double k) {
    return p * ((double)sin(a*k + b) + (double)cos(c*k + d) + 2.0);
}

int main() {
    int p, a, b, c, d, n;
    cin >> p >> a >> b >> c >> d >> n;
    double maxPrice = 0.0, maxDecline = 0.0;
    double currPrice;
    for (int i=1; i<=n; i++) {
        currPrice = price((double)p, (double)a, (double)b, (double)c, (double)d, (double)i);
        maxPrice = max(maxPrice, currPrice);
        maxDecline = max(maxDecline, maxPrice - currPrice);
    }
    cout << setprecision(10) << maxDecline << endl;
    return 0;
}