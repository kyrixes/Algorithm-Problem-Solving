#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (const vector<int>& command : commands) {
        vector<int> sub_array(array.begin() + command[0] - 1, array.begin() + command[1]);
        sort(sub_array.begin(), sub_array.end());
        answer.push_back(sub_array[command[2] - 1]);
    }
    
    return answer;
}
