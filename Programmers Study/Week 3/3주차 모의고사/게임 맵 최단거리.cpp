#include <vector>
#include <queue>

using namespace std;

int nX[4] = {-1, 0, 1, 0};
int nY[4] = {0, 1, 0, -1};

int solution (vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<bool>> visited (n, vector<bool>(m, false));   // 방문 여부 체크 벡터
    vector<vector<int>>     dist (n, vector<int> (m,    -1));   // 거리 계산 벡터
    
    dist[0][0] = 0;
    
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nextX = x + nX[i];
            int nextY = y + nY[i];
            
            // 범위를 벗어난 경우
            if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= m)
                continue;
            
            // 아직 방문하지 않은 칸이라면
            if (!visited[nextX][nextY] && maps[nextX][nextY] == 1) {
                dist[nextX][nextY] = dist[x][y] + 1;
                visited[nextX][nextY] = true;
                q.push(make_pair(nextX, nextY));
            }
        }
    }
    
    int answer = dist[n - 1][m - 1];
    
    return (answer == -1) ? -1 : answer + 1;
}
