#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> answer = {0, 0};

    for (int i = 0; i < 3; i++) {
        answer[0] ^= v[i][0];
        answer[1] ^= v[i][1];
    }

    return answer;
}
