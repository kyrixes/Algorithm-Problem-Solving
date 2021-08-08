#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    // 오름차순으로 정렬된 우선순위 큐
    priority_queue<int, vector<int>, greater<int>> pq (scoville.begin(), scoville.end());
    
    while (pq.top() < K) {
        // 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우
        if (pq.size() <= 1)
            return -1;
        
        int food_first = pq.top();  pq.pop();
        int food_second = pq.top();  pq.pop();
        
        // 조합
        pq.push(food_first + food_second * 2);
        
        ++answer;
    }
    
    return answer;
}
