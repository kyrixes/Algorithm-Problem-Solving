#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> clothes(n, 1);

    for (int i : lost)    --clothes[i - 1];
    for (int i : reserve) ++clothes[i - 1];

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (clothes[i] == 0) {
            if (i > 0 && clothes[i - 1] == 2) {
                --clothes[i - 1];
                ++clothes[i];
            } else if (i < n - 1 && clothes[i + 1] == 2) {
                --clothes[i + 1];
                ++clothes[i];
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (clothes[i] > 0)
            count++;
    
    return count;
}
