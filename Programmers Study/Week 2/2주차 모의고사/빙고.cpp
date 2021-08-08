#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<int>> board, vector<int> nums) {
    int answer = 0;

    int n = board[0].size();
    int r = 0, c = 0, d1 = 0, d2 = 0;
        
    unordered_map<int, int> u;
    for (int i = 0; i < nums.size(); i++)
        u[nums[i]] = nums[i];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (u.find(board[i][j]) != u.end()) board[i][j] = 0;
    
    for (int i = 0; i < n; i++) {
        r = 0; c = 0;
        for (int j = 0; j < n; j++) {
            r += board[i][j]; c += board[j][i];
            if (i == j) d1 += board[i][j];
            if (i + j == N - 1) d2 += board[i][j];
        }
        if (r == 0) answer++; if (c == 0) answer++;
    }
    if (d1 == 0) answer++; if (d2 == 0) answer++;
    
    return answer;
}
