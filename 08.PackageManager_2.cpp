#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N);
    vector<int> inDegree(N, 0);
    priority_queue<int, vector<int>, greater<int>> q;  // Min-heap for the smallest numerical value
    vector<int> topoOrder;

    for (int i = 0; i < M; ++i) {
        int X, Y;
        cin >> X >> Y;
        adj[X].push_back(Y);
        inDegree[Y]++;
    }

    for (int i = 0; i < N; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.top();
        q.pop();
        topoOrder.push_back(node);

        for (int neighbour : adj[node]) {
            inDegree[neighbour]--;
            if (inDegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    if (topoOrder.size() != N) {
        cout << "circular dependency" << endl;
    }
    else {
        for (int i = 0; i < N; ++i) {
            if (i > 0) cout << " ";
            cout << topoOrder[i];
        }
        cout << endl;
    }

    return 0;
}
