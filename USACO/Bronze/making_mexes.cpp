#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n), occ(n+1), ans(n+1);
    for (int i=0; i<n; i++) {
        cin >> v[i];
        occ[v[i]]++; // increment the map with key of element v[i]
    }
    int filled = 0; // keep track of how many integers need to be filled by future mex calculations
    for (int i=0; i<=n; i++) { // iterate through all desired mex values from 0 to n
        // if (!occ[i]) { // if the desired mex value already isn't in the arr
        //     ans[i] = filled; // fill in all previous holes, this is the optimal answer
        //     filled++; // add new hole to count
        // }
        // else { // else if the desired value is in the array
        //     ans[i] = max(filled, occ[i]); // use it to fill the previous holes and change any extra instances of that number
        // }
        ans[i] = max(filled, occ[i]);
        filled += (occ[i])? 0: 1;
        cout << ans[i] << endl;
    }
}