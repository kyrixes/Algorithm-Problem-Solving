#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> seat) {
    sort(seat.begin(), seat.end());
    seat.erase(unique(seat.begin(), seat.end()), seat.end());
    return seat.size();
}
