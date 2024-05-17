#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// The 8 possible movements for a knight in chess
const int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// Function to check if a position is within the chessboard bounds
bool isValid(int x, int y, int N) {
    return x >= 0 && y >= 0 && x < N && y < N;
}

// Function to find the minimum number of moves using BFS
int minKnightMoves(int N, int R, int C, int T, int F) {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<pair<pair<int, int>, int>> q;  // Queue to store <position, moves>

    // Start BFS from the initial position of the knight
    q.push({ {R, C}, 0 });
    visited[R][C] = true;

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        int x = front.first.first;
        int y = front.first.second;
        int moves = front.second;

        
        if (x == T && y == F) {
            return moves;
        }

        // Explore all possible moves of a knight
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Check if the new position is valid and not visited
            if (isValid(nx, ny, N) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ {nx, ny}, moves + 1 });
            }
        }
    }

    return -1;  
}

int main() {
    int N, R, C, T, F;
    cin >> N >> R >> C >> T >> F;

    int result = minKnightMoves(N, R, C, T, F);
    cout << result << endl;

    return 0;
}
