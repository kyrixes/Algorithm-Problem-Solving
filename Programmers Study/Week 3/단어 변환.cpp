#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool check (const string& current, const string& word) {
    int count = 0;
    for (int i = 0; i < current.length(); i++) {
        if (current[i] != word[i]) {
            count++;
            if (count > 1)
                return false;
        }
    }

    return true;
}

int solution (string begin, string target, vector<string> words) {
    // words에 target이 없으면 종료
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;

    unordered_map<string, bool> visited;
    for (const string& word : words)
        visited[word] = false;
    
    queue<pair<string, int>> q;
    q.push({begin, 0});

    while (!q.empty()) {
        string current = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (visited[current])
            continue;

        visited[current] = true;
        
        // target 단어와 일치하는 경우 거리 return
        if (current == target)
            return dist;

        // 올바르게 변환된 경우 거리 증가
        for (const string& word : words) {
            if (!visited[word] && check(current, word)) {
                q.push({word, dist + 1});
            }
        }
    }

    return 0;
}
