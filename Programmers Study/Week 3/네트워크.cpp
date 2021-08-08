#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n, false);
    int num_networks = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;

        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            if (visited[u])
                continue;

            visited[u] = true;

            for (int v = 0; v < n; v++) {
                if (computers[u][v] && !visited[v])
                    q.push(v);
            }
        }

        num_networks++;
    }

    return num_networks;
}
