#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <fstream>

using namespace std;

int main() {
    int n;
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    vector<vector<int> > v(n, vector<int>(3));
    vector<vector<int> > adj(n);
    for (int i=0; i<n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        for (int j=0; j<i; j++) {
            int dx, dy;
            dx = abs(v[i][0] - v[j][0]);
            dy = abs(v[i][1] - v[j][1]);
            if (v[i][2]*v[i][2] >= dx*dx + dy*dy) adj[i].push_back(j);
            if (v[j][2]*v[j][2] >= dx*dx + dy*dy) adj[j].push_back(i);
        }
    }
    int best = 1;
    auto bfs = [&] (int n) {
        int count = 0;
        deque<int> dq;
        dq.push_back(n);
        set<int> vis;
        while (!dq.empty()) {
            int curr = dq.front();
            dq.pop_front();
            if (vis.count(curr)) continue;
            count++;
            vis.insert(curr);
            for (int x: adj[curr]) if (!vis.count(x)) dq.push_back(x);
        }
        best = max(best, count);
    };
    for (int i=0; i<n; i++) {
        bfs(i);
    }
    cout << best << endl;
}