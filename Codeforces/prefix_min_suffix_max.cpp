#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n), res(n); // v is for input, res is answers
        for (int i=0; i<n; i++) { // take in input
            cin >> v[i];
            res[i] = 0; // make sure to set all elements in res vector to 0; also, though there are other ways to do this, this is how I chose to
        }
        int curr_min = v[0]; // set min value to first element for forward sweep
        int curr_max = v[n-1]; // set max value to last element for backward sweep
        for (int i=n-1; i>=0; i--) { // do backward sweep first
            if (v[i] >= curr_max) { // if the current value is bigger than prev max
                curr_max = v[i]; // set new max
                res[i] = 1; // this element is possible
            }
        }
        for (int i=0; i<n; i++) { // do forward sweep and print out answers concurrently
            if (v[i] <= curr_min) { // if the current value is less than prev min
                curr_min = v[i]; // set new min
                res[i] = 1; // this element is possible
            }
            cout << res[i]; // at this point, if the current element is possible it will have value 1 because we already did the backwards sweep
            // so after processing this element in the forward pass we can print out if it is possible or not
        }
        // this ordering of backwards sweep then forwards sweep saves us needing to write an extra for loop; complexity-wise, it doesn't change anything! Just a way to simplify your code!
        cout << endl;
    }
}