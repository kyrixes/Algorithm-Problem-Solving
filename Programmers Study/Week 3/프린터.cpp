#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }

    int answer = 0;
    
    while (!q.empty()) {
        auto rqst = q.front();
        q.pop();
        
        if (rqst.first == pq.top()) {
            pq.pop();
            ++answer;
            
            if (rqst.second == location)
                return answer;
        } else {
            q.push(rqst);
        }
    }

    return answer;
}
