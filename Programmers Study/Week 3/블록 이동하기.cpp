#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

// 로봇의 위치&자세 표현 자료형
// 가로 방향인 경우 (r, c)는 왼쪽 좌표, 세로 방향인 경우 (r, c)는 상단 좌표.
class robot
{
public:
    int r = 0; // row
    int c = 0; // column
    int d = 0; // direction (0: 가로, 1: 세로)

    robot(int _r, int _c, int _d) : r(_r), c(_c), d(_d) {}
};

int solution(vector<vector<int>> board) {
    int N = (int)board.size();

    const int dc[4] = {1,  0, -1,  0};
    const int dr[4] = {0,  1,  0, -1};

    auto is_target = [N](int r, int c, int d) {
        return (r == N - 1 && c == N - 2 && d == 0) ||
            (r == N - 2 && c == N - 1 && d == 1);
    };

    auto is_valid = [&board, N](int r, int c) {
        return (r >= 0 && r < N) && (c >= 0 && c < N) && (board[r][c] == 0);
    };

    // BFS를 위한 큐
    queue<robot> q;

    // distance를 저장할 맵. -1은 방문하지 않음을 의미.
    vector<vector<vector<int>>> dist(N, vector<vector<int>>(N, vector<int>(2, -1)));

    q.push(robot(0, 0, 0)); // (0, 0), 가로 방향
    dist[0][0][0] = 0;

    while (!q.empty()) {
        robot curr = q.front();
        q.pop();

        // 로봇의 시작 좌표 (왼쪽 또는 윗쪽)
        int curr_r1 = curr.r;
        int curr_c1 = curr.c;
        int curr_d1 = curr.d; // 방향

        // 로봇의 나머지 좌표 (오른쪽 또는 아래쪽)
        int curr_r2 = curr_r1 + dr[curr_d1];
        int curr_c2 = curr_c1 + dc[curr_d1];

        int cost = dist[curr_r1][curr_c1][curr_d1];

        // 타겟에 도달했으면 종료
        if (is_target(curr_r1, curr_c1, curr_d1)) {
            return cost;
        }

        // 1. 상하좌우 이동
        for (int i = 0; i < 4; i++) {
            int next_r1 = curr_r1 + dr[i];
            int next_c1 = curr_c1 + dc[i];
            int next_r2 = curr_r2 + dr[i];
            int next_c2 = curr_c2 + dc[i];

            if (!is_valid(next_r1, next_c1)) continue;
            if (!is_valid(next_r2, next_c2)) continue;
            if (dist[next_r1][next_c1][curr_d1] != -1) continue;

            dist[next_r1][next_c1][curr_d1] = cost + 1;
            q.push(robot(next_r1, next_c1, curr_d1));
        }

        // 2. 회전
        for (int t = 0; t < 2; t++) {
            for (int i = 0; i < 4; i++) {
                int next_r1 = curr_r1;
                int next_c1 = curr_c1;
                int next_r2 = curr_r1 + dr[i];
                int next_c2 = curr_c1 + dc[i];

                int dist_r = abs(curr_r2 - next_r2);
                int dist_c = abs(curr_c2 - next_c2);

                // 시계, 반시계 방향으로 90도 회전한 경우가 아니거나
                // 회전하여 이동할 지점이 비어있지 않은 경우
                if (dist_r != 1 || dist_c != 1) continue;

                if (!is_valid(next_r2, next_c2)) continue;

                // 회전 시 대각 위치가 비어있지 않은 경우
                int diag_r = curr_r1 ^ curr_r2 ^ next_r2;
                int diag_c = curr_c1 ^ curr_c2 ^ next_c2;

                if (!is_valid(diag_r, diag_c)) continue;

                // 회전 후, 좌표 정렬 및 direction 조정 후 큐에 등록
                if (next_r1 > next_r2) swap(next_r1, next_r2);
                if (next_c1 > next_c2) swap(next_c1, next_c2);
                int next_d1 = (curr_d1 == 0) ? 1 : 0;

                if (dist[next_r1][next_c1][next_d1] == -1) {
                    dist[next_r1][next_c1][next_d1] = cost + 1;
                    q.push(robot(next_r1, next_c1, next_d1));
                }
            }

            swap(curr_r1, curr_r2);
            swap(curr_c1, curr_c2);
        }
    }

    return -1;
}
