#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    
    int tmp = routes[0][1];
    for (auto r : routes) {
        if (tmp < r[0]) {
            answer++;
            tmp = r[1];
        }
        
        if (tmp >= r[1])
            tmp = r[1];
    }
    
    return answer;
}
