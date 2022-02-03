#include <vector>
#include <algorithm>
using namespace std;

int rrank(int matched) {
    if (matched < 2) {
        return 6;
    }
    else {
        return 7 - matched;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int matched = 0;
    int undecided = 0;
    
    for (int i = 0; i < 6; i++) {
        if (find(lottos.begin(), lottos.end(), win_nums[i]) != lottos.end()) {
            ++matched;
        }
        
        if (!lottos[i]) {
            ++undecided;
        }
    }
    
    return { rrank(matched + undecided), rrank(matched) };
}
