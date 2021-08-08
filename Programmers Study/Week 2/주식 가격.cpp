#include <vector>
#include <stack>

using namespace std;

vector<int> solution (vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    
    for (int i = 0; i < prices.size(); i++) {
        for (int j = i + 1; j < prices.size(); j++) {
            ++answer[i];
            
            if (prices[j] < prices[i])
                break;
        }
    }
    
    return answer;
}

// Using Stack
vector<int> solution2 (vector<int> prices)
{
    vector<int> answer(prices.size());
    stack<int> s;

    for (int i = 0; i < prices.size(); i++) {
        while (!s.empty() && prices[i] < prices[s.top()]) { // 현재 주차 가격 < 이전 주차 가격
            answer[s.top()] = i - s.top(); // 이전 주차 가격 = 현재 주차 - 이전 주차
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty()) {
        answer[s.top()] = (int)prices.size() - s.top() - 1;
        s.pop();
    }

    return answer;
}
